#include <iostream>
#include <exception>

class StockInsuffisantException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Stock Insuffisant!";
    }
};

class Produit
{
private:
    std::string nom;
    double prix;
    int quantite;

public:
    Produit(std::string n, double p, int q) : nom(n), prix(p), quantite(q) {}

    void vendre(int quantite)
    {
        if (this->quantite < quantite)
        {
            throw StockInsuffisantException();
        }
        this->quantite -= quantite;
        std::cout << quantite << " de " << this->nom << " ont ete vendus!" << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    Produit p1("parfum", 44.99, 15);
    Produit p2("biscuit", 2.00, 5);
    try
    {
        p1.vendre(14);
        p2.vendre(10);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erreur: " << e.what() << '\n';
    }

    return 0;
}
