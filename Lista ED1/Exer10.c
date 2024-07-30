#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int tam = 0;
    int caminho;
    char (*criancas)[30] = malloc(tam * sizeof(char));


    int aux;
    int auxUm = 0;
    int valoraux;
    int retirador = 0;
    
    scanf("%d", &tam);
    
    int valor[tam];

    for(aux = 0; aux < tam; aux++) {
        auxUm += 1;
        criancas = realloc(criancas, auxUm * sizeof(*criancas));
        
        scanf("%s %d", criancas[aux], &valor[aux]);
    }
    
    auxUm = 0;
    
    while (tam > 1) {
        if(auxUm == 0){
            valoraux = valor[auxUm];
            auxUm += 1;
        }
        
        retirador = valoraux % tam;
        caminho = valoraux % 2;
        
        if(retirador == 0){
            valoraux = valor[0];
            
            strcpy(criancas[0], criancas[1]);
            valor[0] = valor[1];
            
            for(aux = 1; aux < (tam - 1); aux++){
                strcpy(criancas[aux], criancas[aux + 1]);
                valor[aux] = valor[aux + 1];
            }
            
        } else if(caminho != 0){
            valoraux = valor[retirador];
            
            for(aux = retirador; aux < (tam - 1); aux++){
                strcpy(criancas[aux], criancas[aux + 1]);
                valor[aux] = valor[aux + 1];
            }
        } else if(caminho == 0){
            valoraux = valor[(tam - retirador)];

            for(aux = (tam - retirador); aux < (tam - 1); aux++){
                auxUm = valor[retirador];
                strcpy(criancas[aux], criancas[aux + 1]);

                valor[aux] = valor[aux + 1];
            }
        }
        
        tam -= 1;
        criancas = realloc(criancas, tam * sizeof(*criancas));
    }

    printf("%s\n", criancas[0]);
    return 0;
}