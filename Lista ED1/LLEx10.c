#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int tamanho = 0;
    int way;
    char (*kids)[30] = malloc(tamanho * sizeof(char));


    int Auxiliar;
    int AuxiliarUm = 0;
    int valorAuxiliar;
    int retirador = 0;
    
    scanf("%d", &tamanho);
    
    int valor[tamanho];

    for(Auxiliar = 0; Auxiliar < tamanho; Auxiliar++) {
        AuxiliarUm += 1;
        kids = realloc(kids, AuxiliarUm * sizeof(*kids));
        
        scanf("%s %d", kids[Auxiliar], &valor[Auxiliar]);
    }
    
    AuxiliarUm = 0;
    
    while (tamanho > 1) {
        if(AuxiliarUm == 0){
            valorAuxiliar = valor[AuxiliarUm];
            AuxiliarUm += 1;
        }
        
        retirador = valorAuxiliar % tamanho;
        way = valorAuxiliar % 2;
        
        if(retirador == 0){
            valorAuxiliar = valor[0];
            
            strcpy(kids[0], kids[1]);
            valor[0] = valor[1];
            
            for(Auxiliar = 1; Auxiliar < (tamanho - 1); Auxiliar++){
                strcpy(kids[Auxiliar], kids[Auxiliar + 1]);
                valor[Auxiliar] = valor[Auxiliar + 1];
            }
            
        } else if(way != 0){
            valorAuxiliar = valor[retirador];
            
            for(Auxiliar = retirador; Auxiliar < (tamanho - 1); Auxiliar++){
                strcpy(kids[Auxiliar], kids[Auxiliar + 1]);
                valor[Auxiliar] = valor[Auxiliar + 1];
            }
        } else if(way == 0){
            valorAuxiliar = valor[(tamanho - retirador)];

            for(Auxiliar = (tamanho - retirador); Auxiliar < (tamanho - 1); Auxiliar++){
                AuxiliarUm = valor[retirador];
                strcpy(kids[Auxiliar], kids[Auxiliar + 1]);

                valor[Auxiliar] = valor[Auxiliar + 1];
            }
        }
        
        tamanho -= 1;
        kids = realloc(kids, tamanho * sizeof(*kids));
    }

    printf("%s\n", kids[0]);
    return 0;
}
