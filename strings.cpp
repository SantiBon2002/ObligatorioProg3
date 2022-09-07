#include "strings.h"

void scan(strings &cadena)
{
    int i=0;
    char tecla;
    fflush(stdin);
    scanf("%c",&tecla);
    while(tecla!='\n'&&i<S-1)
    {
        cadena[i]=tecla;
        scanf("%c",&tecla);
        i++;
    }
    cadena[i]='\0';
}

void print(strings cadena)
{
    int i=0;
    while(cadena[i]!='\0')
    {
        printf("%c",cadena[i]);
        i++;
    }

}

int strlar(strings cadena)
{
    int i=0,suma=0;

    while(cadena[i]!='\0')
    {
        suma++;
        i++;
    }
    return suma;

}

boolean strmen(strings cadena,strings cadena2)
{
    boolean aux=False;

    boolean menor=False;
    int i=0;


    while(aux==False)
    {
        if(cadena[i]==cadena2[i])
            i++;

        else
        {
            if(cadena[i]<cadena2[i])
                menor=True;
            else
                menor=False;

            aux=True;
        }

    }


    return menor;
}

boolean streq(strings cadena,strings cadena2)
{
    int i=0;
    boolean encontre=False;
    do
    {

        if(cadena[i]==cadena2[i])
            i++;
        else
            encontre=True;

    }
    while(encontre==False&&(cadena[i]!='\0'||cadena2[i]!='\0'));

    return encontre;
}

void strcop(strings &cadena,strings cadena2)
{
    int i=0;
    while(cadena2[i]!='\0')
    {
        cadena[i]=cadena2[i];
        i++;
    }
    cadena[i]='\0';
}

void strcon(strings &cadena,strings cadena2)
{
    int i=0,suma=0;

    while(cadena[i]!='\0')
    {
        suma++;
        i++;
    }
    i=0;

    while(cadena2[i]!='\0')
    {
        cadena[suma]=cadena2[i];
        suma++;
        i++;
    }
    cadena[suma]='\0';
}

void strswp(strings &cadena,strings &cadena2)
{
    strings aux;
    int i=0;

    while(cadena[i]!='\0')
    {
        aux[i]=cadena[i];
        i++;
    }
    aux[i]='\0';
    i=0;

    while(cadena2[i]!='\0')
    {
        cadena[i]=cadena2[i];
        i++;
    }
    cadena[i]='\0';
    i=0;

    while(aux[i]!='\0')
    {
        cadena2[i]=aux[i];
        i++;
    }
    cadena2[i]='\0';
}
