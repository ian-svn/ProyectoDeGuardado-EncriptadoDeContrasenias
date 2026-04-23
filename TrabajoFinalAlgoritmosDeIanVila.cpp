#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <vector>
#include <string>


struct contraAniadida
{
	int id_contra;
	char aplicacion[100];
	char usuario[100];
	char contra[100];
};

contraAniadida contras[100];

char menu()
{
	char operacion;
	
	printf("\n\n    8 - Salir");
	printf("\n\n\n\t\t\t     +----------------------------------------------------------+");
	printf("\n\t\t\t     | Programa para encriptar contrase%cas a nivel indecifrable |",164);	
	printf("\n\t\t\t     +----------------------------------------------------------+");
	printf("\n\n\t\t\t  1- Ingresar una nueva contrase%ca     2- Encriptar una contrase%ca     \n\n\t\t\t 3- Desencriptar una contrase%ca     4- Modificar una contrase%ca      \n\n\t\t\t 5- Borrar una contrase%ca      6- Mostrar contrase%cas      7- BorrarTodo ",164,164,164,164,164,164);
	
	printf("\n\n\n\t\t Ahora la operacion que quiere realizar: ");
	operacion = getch();
	printf("\n");
	
	return operacion;
}

int cantIngresados()
{
	int aux;
	FILE * fpr;
	fpr = fopen("CantRegistros.txt","r");
		
		fscanf(fpr,"%d",&aux);
		
	fclose(fpr);
	return aux;
}


int x;
int dim;



int PrimeraVezO_No() //  devuelve 2 si se abrió más de una vez el programa es decir si en el archivo dice '1' o no. si dice un devuelve 1 si no 2.
{
	FILE * fpr;
	fpr = fopen("cantVecesAbiertas.txt","r");
		
		int cantVecesAbiertas;
		
		cantVecesAbiertas = fscanf(fpr,"%d",&cantVecesAbiertas);
		
		if(cantVecesAbiertas == 1)
		{
			return 1;
		}
		else
		{
			return 2;
		}
		fclose(fpr);
	}
int VecesProgramaAbierto()  // cuenta las veces que entras al programa, es decir le va sumando uno a el numero del archivo.  mal
{	
	int cantVecesAbiertas,numero;
	
	FILE * fpr;
	fpr = fopen("cantVecesAbiertas.txt","r+");
	
		fscanf(fpr,"%d",&cantVecesAbiertas);
		rewind(fpr);
		cantVecesAbiertas++;
		fprintf(fpr,"%d",cantVecesAbiertas);
	
	fclose(fpr);
	
	return cantVecesAbiertas;
}

void CrearArchivo()
{
	FILE * fpw;
	fpw = fopen("cantVecesAbiertas.txt","w");
		
		int numero = 1;
				
		fprintf(fpw,"%d",numero);
		
	fclose(fpw);
}

void AccesoPrimeraVez()		//    primera vez que entra a la aplicacion. 
{
	char password[100];
	
	printf("\n\n\t\t\t Ingrese la contrase%ca que utilizar%c a partir de ahora: ",164,160);
	gets(password);
	dim = strlen(password);
	
	FILE * fpw;
	fpw = fopen("contraseñaAcceso.txt","w");
	
	fprintf(fpw,"%s",password);
	
	fclose(fpw);
}

int Acceder()           	//     compara la contraseña guarda con la que ingresará ahora
{
	char contraAcceso[100];
	std::vector<char> contraIngresada;
	int y=0,cont=0,dim1;
	
	printf(" Ingrese la contrase%ca: ",164);
	
	char caracter;
	caracter = getch();
	
	contraIngresada.clear();
	
	
	while(caracter != 13)
	{
		contraIngresada.push_back(caracter);
		printf("*");
		caracter = getch();
	}
	
	fflush(stdin);
	
	FILE * fpr;
	fpr = fopen("contraseñaAcceso.txt","r");
		
		fread(contraAcceso, 1, sizeof(contraAcceso), fpr);
				
		
				
		dim = strlen(contraAcceso);
		dim1 = contraIngresada.size();
		
		for(y=0;y<dim;y++)
		{   
			if(contraAcceso[y]==contraIngresada[y] & dim == dim1)
			{
				cont++;
			}
			else
			{
				cont-20;
			}
		}
		
		if(cont == dim)
		{
			return 1;
		}
		else if(cont!=dim)
		{
			return 0;
		}
	
	fclose(fpr);
}

void  crearArchivoX()
{
	FILE * fpw;
	fpw = fopen("CantRegistros.txt","w");
		fprintf(fpw,"%d",0);
	fclose(fpw);
}

void AniadirContra()
{	
	int id_contra;
	char aplicacion[100];
	char usuario[100];
	char contra[100];
	
	
	
	FILE * fpw;
	fpw = fopen("CantRegistros.txt","r+");
				
		fscanf(fpw,"%d",&x);
		rewind(fpw);
		x++;
		fprintf(fpw,"%d",x);
	
	fclose(fpw);
	
	FILE * fpa;
	fpa = fopen("Contraseñas.txt","a");
		
		int id = x;
		
		printf("\n\n\t\t El id es: %d",x);
		id_contra = x;
		printf("\n\t\t Ingrese el nombre de la aplicacion: ");
		gets(aplicacion);
		printf("\n\t\t Ingrese el usuario: ");
		gets(usuario);
		printf("\n\t\t Ingrese la contrase%ca: ",164);
		gets(contra);
		fprintf(fpa,"\n%d      %s      %s      %s",id_contra,aplicacion,usuario,contra);
		
	fclose(fpa);
}

void BorrarTodo()
{
	FILE * fpw1;
	FILE * fpw;
	fpw = fopen("Contraseñas.txt","w");
	fpw1 = fopen("CantRegistros.txt","w");
	fprintf(fpw1,"%d",0);
	fclose(fpw);
	fclose(fpw1);
}

leerTodoAsignarStructs()
{
		FILE * fpr;	
		fpr = fopen("Contraseñas.txt","r");
				

	    if (fpr == NULL) {
			return 0;
	    }
	
	    int aux = 0;
	    int aux1 = x; // Utiliza aux para seguir la posición de la estructura contras.
	
    	while (fscanf(fpr, "%d  %s  %s  %s",&contras[aux].id_contra, contras[aux].aplicacion, contras[aux].usuario,contras[aux].contra) != EOF) {
						
			if (contras[aux].id_contra == 0 ) { // Evita desbordamiento del array.
        	    break;
        	}
			
    	    // printf("ID: %d\nUsuario: %s\nAplicación: %s\nContraseña: %s\nContraseña encriptada: %s\n\n",contras[aux].id_contra, contras[aux].usuario, contras[aux].aplicacion,contras[aux].contra, contras[aux].contraEncriptada);
        	
        	aux++; // Avanza al siguiente elemento del array.
        	

        	
    	}
    
    fclose(fpr);
}




void escribirTodoStructs()
{
	FILE * fpw;
	fpw = fopen("Contraseñas.txt","w");
		
		int aux;
		
		for(aux=0;aux!=x;aux++)
		{
			fprintf(fpw,"\n\t\t %d  %s  %s  %s",contras[aux].id_contra, contras[aux].aplicacion, contras[aux].usuario,contras[aux].contra);
		}
		
	fclose(fpw);
}

/*
void leerTodoAsignarStructs() {
    FILE *fpr;
    fpr = fopen("Contraseñas.txt", "r");

    if (fpr == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    int aux = 2;
    int aux1 = x; // Utiliza aux para seguir la posición de la estructura contras.

    while (fscanf(fpr, "id: %d Usuario: %s Aplicacion: %s Contrase%ca: %s Contrase%ca encriptada: %s",						no entiendo por que no funciona ni como seguir con
                  &contras[aux].id_contra, contras[aux].usuario, contras[aux].aplicacion,									que hacer para que si funcione :///.
                  contras[aux].contra, contras[aux].contraEncriptada) == 6) {
        aux++; // Avanza al siguiente elemento del array.
        printf("ID: %d\nUsuario: %s\nAplicación: %s\nContraseña: %s\nContraseña encriptada: %s\n\n",
               contras[aux].id_contra, contras[aux].usuario, contras[aux].aplicacion,
               contras[aux].contra, contras[aux].contraEncriptada);
        
        if (aux >= 100 || aux == aux1) { // Evita desbordamiento del array.
            break;
        }
    }

    getch();
    
    fclose(fpr);
}
*/


int mostrarcontras()
{
	FILE * fpr;
	fpr = fopen("Contraseñas.txt","r");
	 
	fseek(fpr,0,SEEK_END);
	int size = ftell(fpr);
	
	rewind(fpr);
	
	fclose(fpr);
	
	if(size == 0)
	{
		printf("\n\n\n\n\t\t\t\t\t No hay ninguna contrase%cas guardada... ",164);
		getch();
		return 0;
	}
	
	system("cls");
	
	FILE * ftrp;
				
	ftrp = fopen("Contraseñas.txt","r");
					
	printf("\n\n");
					
	char todoArchivo[5000];
				
	while(fgets(todoArchivo,100,ftrp))
	{
		printf("\n\t %s",todoArchivo);
	}
	fclose(ftrp);
							
	printf("\n\n\n\n\t\t\t\t\t Estas son las contrase%cas guardadas... ",164);
	getch();
}

int modificarContra()
{
	int aux;
	char operacion;
	int y;
	system("cls");
	printf("\n\n\n\t\t %cSeguro que quieres eliminar alguna contrase%ca? ",168,164);
	printf("\n\n\t\t\t 1- Aceptar         2- Cancelar ");
	
	printf("\n\n\n\t\t Ahora la operacion que quiere realizar: ");
	operacion = getch();
	
    if (operacion == '1') {
	do
	{
		system("cls");
		
		printf("\n\n\t\t\t\t Estas son las contrase%cas que podrá modificar: ");
		
		FILE * ftrp;
					
		ftrp = fopen("Contraseñas.txt","r");
						
		printf("\n\n");
						
		char todoArchivo[5000];
					
		while(fgets(todoArchivo,100,ftrp))
		{
			printf("\n\t %s",todoArchivo);
		}
		fclose(ftrp);
		
		printf("\n\n\n\t\t A indicar por numero de id %cQue contrase%ca es la que quiere cambiar?:  ",168,164);
		scanf("%d",&aux);
	
		
	}while(aux<=0 || aux>x);

	aux = aux-1;
	
	printf("\n\t\t\t El id seguira siendo %d ",contras[aux].id_contra);
	
	printf("\n\n\t\t\t Ingrese el nombre de la aplicacion: ");
	scanf("%s",&contras[aux].aplicacion);
	
	printf("\n\t\t\t Ingrese el usuario: ");
	scanf("%s",&contras[aux].usuario);
	
	printf("\n\t\t\t Ingrese la contrase%ca: ",164);
	scanf("%s",&contras[aux].contra);
	
	}
	
	
	else if(operacion != '1')
	{
		return 0;
	}
	
}

leerX()
{
	FILE * fpr;
	fpr = fopen("CantRegistros.txt","r");
		
		fscanf(fpr,"%d",&x);
		
	fclose(fpr);
}


void borrarRegistro() {
    char operacion;
	int aux,y;
	system("cls");
	printf("\n\n\n\t\t %cSeguro que quieres eliminar alguna contrase%ca? ",168,164);
	printf("\n\n\t\t\t 1- Aceptar         2- Cancelar ");
	
	printf("\n\n\n\t\t Ahora la operacion que quiere realizar: ");
	operacion = getch();
	
    if (operacion == '1') {
        
        system("cls");
        
		int pos;
        
		printf("\n\n\t\t\t\t Estas son las contrase%cas que podrá eliminar: ");
		
		FILE * ftrp;
					
		ftrp = fopen("Contraseñas.txt","r");
						
		char todoArchivo[5000];
					
		while(fgets(todoArchivo,100,ftrp))
		{
			printf("\n\t %s",todoArchivo);
		}
		fclose(ftrp);
		
        do {
            printf("\n\n\n\t\t  Ingrese el n%cmero de ID del registro que desea eliminar: ",163);
            scanf("%d", &pos);
        } while (pos <= 0 || pos > x);

        pos--; // Ajustar pos para que sea 0-indexed

        // Mover los registros hacia atrás para llenar el espacio dejado por el registro eliminado
        for (int i = pos; i < x - 1; i++) {
            contras[i] = contras[i + 1];
        }

        FILE * fpr;
        fpr = fopen("CantRegistros.txt","w+");
        	
        	fscanf(fpr,"%d",&x);
			rewind(fpr);
			x--;
			fprintf(fpr,"%d",x);
        	
        fclose(fpr);

        // Actualizar los IDs de los registros restantes
        for (int i = 0; i < x; i++) {
            contras[i].id_contra = i + 1;
        }
    }
}


char encriptacion(char vector[])
{
	int numero;
	int z;
	char caracter;
	
	int dim = strlen(vector);
	printf("%d",dim);
	for(z=0;z<dim;z++)
	{
		if(z == 0)
		{
			caracter = (vector[z] + 5) - 20 * z-130;
		}
		else if(z!=0)
		{
			caracter = (vector[z] + 5) - z * z -130;			
		}
		if(z!=0 && caracter != 13)
		{
			vector[z] = caracter;
		}	
		
		fflush(stdin);
	}
	
	printf("\n\n\n\t\t\t La contrase%ca encriptada es: ",164);
	fflush(stdin);
	printf("%s",vector);
	
	getch();
	
	// printf("%d    %d",primeraLetra,ultimaLetra);  bien
}

char desencriptacion(char vector[]) 
{
	
	int numero;
	int z;
	
	int dim = strlen(vector);
	char caracter;
	printf("%d",dim);
	
	for (z = 0; z < dim; z++)
    {
// todo bien bld, vos como estas? te felicito por comenzar tu carrera como programador senior
        if (z == 0)
        {
            caracter = (vector[z] - 5) + 20 * z+130;
        }
        else if(z!=0)				// hola amig, todo bien porque yo masomenos bien ya que parece por poco que arereglé el codigo por medio de utilizar muchos fflush jskksj
        {
            caracter = (vector[z] - 5) + z * z+130;
        }
		if(z!=0 && caracter != 13)
		{
			vector[z] = caracter;
		}	
		fflush(stdin);
    }
	fflush(stdin);
	printf("\n\n\n\t\t\t La contrase%ca desencriptada es: ",164);
	fflush(stdin);
	printf("%s",vector);
	fflush(stdin);
	getch();
	
	// printf("%d    %d",primeraLetra,ultimaLetra);  bien
}


int main()
{
	int aux=0;
	int acc;
	int cantVecesAbiertas;
	char operacion;
	char contDe[400];
	char contrEn[400];
	
		cantVecesAbiertas = VecesProgramaAbierto(); // suma la cantidad de veces cuando entras
				
		do
		{
			
		if(cantVecesAbiertas == 1) 
		{
			crearArchivoX();
			CrearArchivo();
			AccesoPrimeraVez(); 						//    primera vez que entra a la aplicacion. 
			cantVecesAbiertas = VecesProgramaAbierto();
		}
		else if(cantVecesAbiertas > 1)
		{
			printf("\n\n\n\n\n\t\t\t");
			acc = Acceder();
			if(acc == 1)
			{
				system("cls");
				do
				{
					leerX();
					leerTodoAsignarStructs();
					fflush(stdin);
					escribirTodoStructs();
				operacion = menu();		
	
				switch(operacion)
				{
					case '1':
						AniadirContra();
						break;
						
					case '2':
						
						
						system("cls");
						
						printf("\n\n\n\t\t\t Ingrese una contrase%ca para que sea encriptada: ");
						gets(contrEn);
						fflush(stdin);
						encriptacion(contrEn);
						
						break;
					
					case '3':

						system("cls");
						
						printf("\n\n\n\t\t\t Ingrese una contrase%ca para que sea desencriptada: ");
						gets(contDe);
						fflush(stdin);
						desencriptacion(contDe);
						
						break;
						
					case '4':
						modificarContra();
						escribirTodoStructs();
						break;
			
					case '5':
						
						borrarRegistro();
						escribirTodoStructs();
						
						break;
						
					case '6':

						mostrarcontras();
						
						break;
						
					case '7':
						system("cls");
						printf("\n\n\n\t\t %cSeguro que quieres borrar todas las contrase%cas? ",168,164);
						printf("\n\n\t\t\t 1- Aceptar         2- Cancelar ");
						
						printf("\n\n\n\t\t Ahora la operacion que quiere realizar: ");
						operacion = getch();
						if(operacion == '1')
						{
							BorrarTodo();
						} 
						break;
						
					case '8':
						printf("\n\n\t\t\t Espero que te hayamos sido util, Saludos ");
						getch();
						printf("\n\n\n");
						return 0;
						break;
					}
			
				system("cls");
										
				if(operacion == '1' || operacion == '2')
				{
					
					leerTodoAsignarStructs();
					fflush(stdin);
					escribirTodoStructs();
				}				
				}while(aux!=6);
			}
			else
			{
				printf("\n\n\t\t Error: Contrase%ca incorrecta ",164);
				getch();
			}
		}
		else
		{
			printf("\n\n\t\t Error: No se encuentra la cantidad de veces que se a abierto el programa... ");
			getch();
			return 0;
		}
		
		system("cls");
		}while(aux==0);

}


