#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int tamanho = 0;
    int tamanhoInicial;
    char (*netos)[21] = malloc(tamanho * sizeof(char));
    int score = 0;
    
    int Auxiliar;
    int AuxiliarUm;
    int AuxiliarDois;
    char netoAuxiliar[21];
    char sentidoAuxiliar[13];
    


    while(1){
        scanf("%s", netoAuxiliar);

        if (strcmp(netoAuxiliar, "FIM") == 0) {
            break;
        }

        tamanho += 1;
        netos = realloc(netos, tamanho * sizeof(*netos));

        strcpy(netos[tamanho - 1], netoAuxiliar);
    }
    
    tamanhoInicial = tamanho;
    
    for(Auxiliar = 0; Auxiliar < tamanhoInicial; Auxiliar++){
        scanf("%s %s", netoAuxiliar, sentidoAuxiliar);

        if(strcmp(sentidoAuxiliar, "horario") == 0){
            for(AuxiliarUm = 0; AuxiliarUm < tamanho; AuxiliarUm++){
                if(strcmp(netoAuxiliar, netos[AuxiliarUm]) == 0 && AuxiliarUm < 2){
                    score += 1;

                    for(AuxiliarDois = AuxiliarUm; AuxiliarDois < tamanho; AuxiliarDois++){
                        strcpy(netos[AuxiliarDois], netos[AuxiliarDois + 1]);
                    }
                    
                    tamanho -= 1;
                    netos = realloc(netos, tamanho * sizeof(*netos));
                    
                    break;
                }
            }
        }
        
        if(strcmp(sentidoAuxiliar, "anti-horario") == 0){
            for(AuxiliarUm = tamanho; AuxiliarUm > -1; AuxiliarUm--){
                if(strcmp(netoAuxiliar, netos[AuxiliarUm]) == 0 && AuxiliarUm > (tamanho - 3)){
                    score += 1;
                    
                    for(AuxiliarDois = AuxiliarUm; AuxiliarDois < tamanho; AuxiliarDois++){
                        strcpy(netos[AuxiliarDois], netos[AuxiliarDois + 1]);
                    }
                    
                    tamanho -= 1;
                    netos = realloc(netos, tamanho * sizeof(*netos));
                    
                    break;
                }
            }
        }
    }
    
    printf("%d", score);
}