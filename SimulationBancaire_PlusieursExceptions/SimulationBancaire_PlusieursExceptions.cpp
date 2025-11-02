#include <iostream>
#include <exception>

class MontantInvalideException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Montant Invalide!";
    }
};

class SoldeInsuffisantException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Solde Insuffisant!";
    }
};

class Compte
{
private:
    std::string nom, code;
    double solde;

public:
    Compte(std::string n, std::string c, double s) : nom(n), code(c), solde(s) {}

    void deposer(double montant)
    {
        if (montant < 0)
        {
            throw MontantInvalideException();
        }
        std::cout << "montant deposer: " << montant << std::endl;
        std::cout << "[" << nom << "] : solde avant le depose : " << solde << std::endl;
        solde += montant;
        std::cout << "[" << nom << "] : solde apres le depose : " << solde << std::endl;
    }

    void retirer(double montant)
    {
        if (montant < 0)
        {
            throw MontantInvalideException();
        }
        if (solde < montant)
        {
            throw SoldeInsuffisantException();
        }
        std::cout << "montant retirer: " << montant << std::endl;
        std::cout << "[" << nom << "] : solde avant le retire : " << solde << std::endl;
        solde -= montant;
        std::cout << "[" << nom << "] : solde apres le retire : " << solde << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    Compte c1("Hassan", "1234567890", 500.00);

    try
    {
        c1.deposer(100);
        c1.retirer(100);
        c1.retirer(10000);
    }
    catch (const MontantInvalideException &e)
    {
        std::cerr << "Erreur :" << e.what() << '\n';
    }
    catch (const SoldeInsuffisantException &e)
    {
        std::cerr << "Erreur :" << e.what() << '\n';
    }

    return 0;
}
