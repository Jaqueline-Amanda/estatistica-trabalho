#include <stdio.h>
#include <math.h>

float erroMedia(float grauConf, float desvPad, float amostra, float media);
float erroProporcao(float grauConf, float sucessoProp, float amostra);
float tamanhoAmostraMedia(float grauConf, float erroMedio, float desvPad);
float tamanhoAmostraProporcao(float grauConf, float p, float erroProp);
int main()
{
    int opcao = 1;
    float amostra, media, grauConf, desvPad;
    float sucessoProp;
    float erroMedio;
    float p, erroProp;
    while(opcao >= 1 && opcao< 5){
        printf("\n\nMenu: \n");
        printf(" [1]Calcular intervalo de confianca para media:\n [2]Calcular intervalo de confianca para proporcao:\n [3]Calcular tamanho da amostra - media:\n [4]Calcular tamanho da amostra - proporcao:\n [0]Sair!\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("Calculando erro para a media\n");
                printf("Amostra (n): ");
                scanf("%f", &amostra);
                printf("Media: ");
                scanf("%f", &media);
                printf("Desvio padrao: ");
                scanf("%f", &desvPad);
                printf("Grau de confianca(90, 95 ou 99): ");
                scanf("%f", &grauConf);
                erroMedia(grauConf, desvPad, amostra, media);
                break;
            case 2:
                printf("\nCalculando erro para proporcao:\n");
                printf("Amostra(n): ");
                scanf("%f", &amostra);
                printf("Sucesso: ");
                scanf("%f", &sucessoProp);
                printf("Grau de confianca(90, 95 ou 99): ");
                scanf("%f", &grauConf);
                erroProporcao(grauConf, sucessoProp, amostra);
                break;
            case 3:
                printf("\nCalculando tamanho da amostra - media:\n");
                printf("Grau de confianca(90, 95 ou 99): ");
                scanf("%f", &grauConf);
                printf("Desvio padrao: ");
                scanf("%f", &desvPad);
                printf("Margem de erro para a media: ");
                scanf("%f",&erroMedio);
                tamanhoAmostraMedia(grauConf, erroMedio, desvPad);
                break;
            case 4:
                printf("\nCalculando tamanho da amostra - proporcao:\n");
                printf("Grau de confianca(90, 95 ou 99): ");
                scanf("%f", &grauConf);
                printf("Valor de p: ");
                scanf("%f", &p);
                printf("Margem de erro para proporcao: ");
                scanf("%f", &erroProp);
                tamanhoAmostraProporcao(grauConf, p, erroProp);
                break;
            case 0: 
                printf("\nSaiu...");
                break;
            default:
                printf("\nOpcao invalida!!!");
                break;
        }
    }
}
float erroMedia(float grauConf, float desvPad, float amostra, float media){
    float Em, Icnegativo, Icpositivo;
    if(grauConf == 90)
        Em = (1.645 *desvPad)/sqrt(amostra);

    else if(grauConf == 95)
        Em = (1.96 *desvPad)/sqrt(amostra);

    else if (grauConf == 99)
        Em = (2.575 *desvPad)/sqrt(amostra);

    Icnegativo = (media - Em);
    Icpositivo = (media + Em);
    printf("\nErro medio(Em): %.2f \nIntervalo de confianca(IC): de %.2f a %.2f", Em, Icnegativo, Icpositivo);
}
float erroProporcao(float grauConf, float sucessoProp, float amostra){
    float p, Ep, Icnegativo, Icpositivo;
    p = sucessoProp/amostra;
    if(grauConf == 90)
        Ep = 1.645 * sqrt(p*(1-p)/amostra);

    else if(grauConf == 95)
        Ep = 1.96 * sqrt(p*(1-p)/amostra);
    
    else if(grauConf == 99)
        Ep = 2.575 * sqrt(p*(1-p)/amostra);
    
    Icnegativo = (p - Ep);
    Icpositivo = (p + Ep);
    printf("\nErro proporcao(Ep): %.2f \nIntervalo de confianca(IC): de %.2f a %.2f", Ep, Icnegativo, Icpositivo);
}
float tamanhoAmostraMedia(float grauConf, float erroMedio, float desvPad){
    float n, tamAmostraMed;
    if(grauConf == 90)
        n = (1.645 * desvPad/erroMedio);
    
    else if(grauConf == 95)
        n = 1.96 * desvPad /erroMedio;

    else if(grauConf == 99)
        n = 2.575*desvPad/erroMedio;

    tamAmostraMed = pow(n,2);
    printf("\nTamanho da amostra media: %.0f", ceil(tamAmostraMed));
}
float tamanhoAmostraProporcao(float grauConf, float p, float erroProp){
    double n, tamAmostraProp;
    if(grauConf == 90)
        tamAmostraProp = pow(1.645, 2) * p * (1-p) / pow(erroProp, 2);
    
    else if(grauConf == 95)
        tamAmostraProp = pow(1.96, 2) * p * (1-p) / pow(erroProp, 2);
    
    else if(grauConf == 99)
        tamAmostraProp = pow(2.575, 2)* p * (1-p) / pow(erroProp, 2);
    
    printf("\nTamanho da amostra proporcao: %.0f", ceil(tamAmostraProp));//ceil --> arredonda na hora de mostrar
}
