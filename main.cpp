#include <iostream>
#include <windows.h>
#include "vaporStudio.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);

    std::cout << "\n\n";
    std::cout << "  ##     ##  ######  ######   ######   ######  \n";
    std::cout << "  ##     ## ##    ## ##   ## ##    ## ##    ## \n";
    std::cout << "  ##     ## ######## ##   ## ##    ## ##    ## \n";
    std::cout << "   ##   ##  ##    ## ######  ##    ## ######   \n";
    std::cout << "    ## ##   ##    ## ##      ##    ## ##   ##  \n";
    std::cout << "     ###    ##    ## ##       ######  ##    ## \n";
    std::cout << "                  S T U D I O\n\n";

    VaporStudio vapor;

    vapor.carregarArquivo();

    int op = -1;
    while(op != 0){
        vapor.menu();
        std::cout << "Opção: ";
        std::cin >> op;

        switch (op)
        {
        case 1:
            vapor.inserirJogo();
            break;
        case 2:
            vapor.listarJogos();
            break;
        case 3:
            vapor.alterarJogo();
            break;
        case 4:
            vapor.removerJogo();
            break;
        case 5:
            vapor.vender();
            break;
        case 6:
            vapor.gerarRelatorio();
            break;
        case 7:
            vapor.exibirUmJogo();
            break;
        case 0: 
            std::cout << "Encerrando o VaporStudio...\n"; 
            break;
        default: 
            std::cout << "Opção inválida! Tente novamente.\n";
            system("pause");
        }
    }

    vapor.salvarArquivo();

    return 0;
}