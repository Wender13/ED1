#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int tam = 0;
    int tamInicial;
    char (*netos)[21] = malloc(tam * sizeof(char));
    int score = 0;
    
    int aux, auxUm, auxDois;
    char netoaux[21];
    char sentidoaux[13];
    


    while(1){
        scanf("%s", netoaux);

        if (strcmp(netoaux, "FIM") == 0) {
            break;
        }

        tam += 1;
        netos = realloc(netos, tam * sizeof(*netos));

        strcpy(netos[tam - 1], netoaux);
    }
    
    tamInicial = tam;
    
    for(aux = 0; aux < tamInicial; aux++){
        scanf("%s %s", netoaux, sentidoaux);

        if(strcmp(sentidoaux, "horario") == 0){
            for(auxUm = 0; auxUm < tam; auxUm++){
                if(strcmp(netoaux, netos[auxUm]) == 0 && auxUm < 2){
                    score += 1;

                    for(auxDois = auxUm; auxDois < tam; auxDois++){
                        strcpy(netos[auxDois], netos[auxDois + 1]);
                    }
                    
                    tam -= 1;
                    netos = realloc(netos, tam * sizeof(*netos));
                    
                    break;
                }
            }
        }
        
        if(strcmp(sentidoaux, "anti-horario") == 0){
            for(auxUm = tam; auxUm > -1; auxUm--){
                if(strcmp(netoaux, netos[auxUm]) == 0 && auxUm > (tam - 3)){
                    score += 1;
                    
                    for(auxDois = auxUm; auxDois < tam; auxDois++){
                        strcpy(netos[auxDois], netos[auxDois + 1]);
                    }
                    
                    tam -= 1;
                    netos = realloc(netos, tam * sizeof(*netos));
                    
                    break;
                }
            }
        }
    }
    
    printf("%d", score);
}