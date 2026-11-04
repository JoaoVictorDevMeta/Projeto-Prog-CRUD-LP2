#include <iostream>
#include <windows.h>
#include "vaporStudio.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);

    VaporStudio vapor;

    vapor.carregarArquivo();

    int op = -1;
    while(op != 0){
        vapor.menu();
        op = VaporStudio::lerOpcao("Opção: ", 0, 7);

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
            break;
        }
    }

    vapor.salvarArquivo();

    return 0;
}