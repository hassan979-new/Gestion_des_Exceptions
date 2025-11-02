#include <iostream>
#include <fstream>
#include <exception>

class FichierIntrouvable : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Le Fichier est untrouvable!";
    }
};

void lireFichier(std::string nomFichier)
{
    std::ifstream fichier(nomFichier);

    if (!fichier.is_open())
    {
        throw FichierIntrouvable();
    }

    std::string line;
    while (std::getline(fichier, line))
    {
        std::cout << line << std::endl;
    }

    fichier.close();
}

int main(int argc, char const *argv[])
{
    try
    {
        lireFichier("fichier.txt");
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erreur: " << e.what() << '\n';
    }

    return 0;
}
