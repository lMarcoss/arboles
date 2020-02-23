#include <stdio.h>
#include "Arbol.h"
#include <gtk/gtk.h>
#include <stdlib.h>
#include<string.h>
# define LIM 50
GtkWidget * Ventana, *window;
ArbolBinario Arbol, busqueda;

int elem;
 int Dato;	


void enter_callback(GtkWidget *widget, GtkWidget *entry)
{
  gchar *entry_text; //Variable que guarda la entrada de números
  FILE *crear ;
  FILE *sal1,*sal2,*sal3,*sal4;

  //Abrimos los archivos Pre.txt,En.txt,Post.txt(Archivos que almacenan sus correspondientes operaciones(Lmpiar el archivo))
  sal1=fopen("Pre.txt","w");
  sal2=fopen("En.txt","w");
  sal3=fopen("Post.txt","w");
  sal4=fopen("Prof.txt","w");
  //EScribimos un espacio en blanco para "Resetear" el archivo
  fprintf(sal1,"");
  fprintf(sal2,"");
  fprintf(sal3,"");
  fprintf(sal4,"");

  //Abrimos el archivo Nodos.txt(Guarda los nodos que seran ingresados y el orden)
  crear= fopen("Nodos.txt", "w");
  //Leemos la entrada que recimos a través de la función GTK_ENTRY y gtk_entry_get_text
  entry_text = gtk_entry_get_text(GTK_ENTRY(entry));
  printf("Números Ingresados: %s\n", entry_text);//Escrimos los números en consola
  fprintf(crear,"%s",entry_text);//Escribimos la variable en el archivo Nodos.txt

  //Cerramos todos los archivos
  fclose(sal1);
  fclose(sal2);
  fclose(sal3);
  fclose(sal4);
  fclose(crear);
  capturar();//
}

void destroy(GtkWidget *widget, gpointer data)
{
	gtk_main_quit(); //Cerramos todo el juego con el boton
}

void destroy_ventana(GtkWidget *widget, gpointer data)
{
	gtk_widget_destroy(window);//Cerramos la ventana abierta actualmente
}

void Acerca_App(int argc, char *argv[])
{
	GtkWidget *window;
	GtkWidget *app, *contenedor;
 //Iniciamos gtk
	gtk_init(&argc, &argv);
  //Creamos la ventana con las caracteristicas
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);//Creamos la ventana
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);//Posicionamos la ventana donde queramos
	gtk_window_set_default_size(GTK_WINDOW(window), 600,300);//Dimensionamos la ventana
	gtk_window_set_title(GTK_WINDOW(window), "Aplicacion");//Colocamos un titulo a la ventana

	app = gtk_image_new_from_file("Imagenes/Juego.png");//Ponemos un fondo el cual contiene información sobre el Juego

	contenedor = gtk_fixed_new();

  gtk_fixed_put(GTK_FIXED(contenedor), app, 0,0);//Colocamos el fondo en el contenedor

	gtk_container_add(GTK_CONTAINER(window), contenedor);//Colocamos el contenedor dentro de la Ventana

	gtk_widget_show_all(window);//Mostramos todos los widgets contenidos en la ventana

	g_signal_connect(window, "destroy",G_CALLBACK(gtk_main_quit), NULL);
	gtk_main();
}

void Acerca_Dev(int argc, char *argv[])
{
  GtkWidget *window;
  GtkWidget *des, *contenedor;

  gtk_init(&argc, &argv);
  //Creamos la ventana con sus respectivas caracteristicas
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
  gtk_window_set_title(GTK_WINDOW(window), "Desarrolladores");

  des = gtk_image_new_from_file	("Imagenes/Juego1.png");//fondo que contiene los nombres de los Desarrolladores

  contenedor = gtk_fixed_new();

  gtk_fixed_put(GTK_FIXED(contenedor), des, 0, 0);//Colocamos el fondo en el contenedor

  gtk_container_add(GTK_CONTAINER(window), contenedor );//Colocamos el contenedor dentro de la Ventana
  gtk_widget_show_all(window);//Mostramos los widgets contenidos en la ventana
	g_signal_connect(window, "destroy",G_CALLBACK(destroy_ventana), NULL);

  gtk_main();

}

void Acerca_de(int argc, char *argv[])
{
	GtkWidget *ventac;
	GtkWidget *contenedor, *fondo;
	GtkWidget *app, *App;
	GtkWidget *developers, *Developers;

	gtk_init(&argc,&argv);
  //Creamos la ventana con sus caracteristicas
	ventac = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(ventac), GTK_WIN_POS_CENTER);
	gtk_window_set_title((GtkWindow *)ventac, "Acerca de");
	gtk_window_set_default_size(GTK_WINDOW(ventac), 400,300);

	fondo = gtk_image_new_from_file("Imagenes/Fondo.jpg");
  //Creamos botones
	app= gtk_button_new();
	developers = gtk_button_new();

	App = gtk_image_new_from_file("Imagenes/Info11.png");//Escogemos imagen para el boton
	gtk_button_set_image (GTK_BUTTON(app),App);//Colocamos la imagen en el boton
	Developers = gtk_image_new_from_file("Imagenes/Devel.png");//Escogemos imagen para el boton
	gtk_button_set_image (GTK_BUTTON(developers), Developers);//Colocamos la imagen en el boton

	contenedor = gtk_fixed_new();

	gtk_fixed_put(GTK_FIXED(contenedor), fondo,0,0);//Colocamos el fondeo dentro del contenedor
	gtk_fixed_put(GTK_FIXED(contenedor), app, 50,80);//Colocamos el boton app en el contenedor
	gtk_fixed_put(GTK_FIXED(contenedor), developers, 50,160);//Colocamos el boton developers en el contenedor

  gtk_container_add(GTK_CONTAINER(ventac), contenedor);//Añadimos el contenedor a ls ventana

	g_signal_connect(G_OBJECT(app), "clicked", G_CALLBACK(Acerca_App),(gpointer) contenedor); //Mandamos a llamar el Acerca_App
  g_signal_connect(G_OBJECT(developers), "clicked", G_CALLBACK(Acerca_Dev),(gpointer) contenedor);//Mandamos a llamar el Acerca_Dev

	gtk_widget_show_all(ventac);//Mostramos todo lo contenido en la ventana
	g_signal_connect (G_OBJECT (ventac), "destroy", G_CALLBACK (destroy_ventana), NULL);
	gtk_main();
}

GtkWidget *TabPre,*TabEn,*TabPost,*TabProf,*TabBus, *TabElim;
char regreso[50];//Varibale para retornar operaciones del arbol
const char *format = "<span foreground='green'>\%s</span>"; //Formato de letra color
char *markup;

void Mostrar_PreOrden(int argc, char *argv[]){
    FILE * fichero;
    fichero = fopen("Pre.txt","r");
    fgets(regreso,50,fichero);
    markup = g_markup_printf_escaped(format,regreso);//Coloca el formato a la cadena

    gtk_label_set_markup(GTK_LABEL(TabPre), markup);//Colocamos lo que imprimiremos dentro de la respectiva label
    PangoFontDescription *font = pango_font_description_from_string("serif, Normal, 16");//font: tipo de letra y tamaño
    gtk_widget_modify_font(TabPre, font);//Modificamos la etiqueta con el font

    fclose(fichero);

    g_free(markup);//Liberamos el markup
}

void Mostrar_EnOrden(int argc, char *argv[]){
    FILE * fichero;
    fichero = fopen("En.txt","r");
    fgets(regreso,50,fichero);
    markup = g_markup_printf_escaped(format,regreso);//Coloca el formato a la cadena

    gtk_label_set_markup(GTK_LABEL(TabEn), markup);//Colocamos lo que imprimiremos dentro de la respectiva label
    PangoFontDescription *font = pango_font_description_from_string("serif, Normal, 16");//font: tipo de letra y tamaño
    gtk_widget_modify_font(TabEn, font);//Modificamos la etiqueta con el font

    g_free(markup);//Liberamos el markup
}

void Mostrar_PostOrden(int argc,char *argv){
    FILE * fichero;
    fichero = fopen("Post.txt","r");
    fgets(regreso,50,fichero);
    markup = g_markup_printf_escaped(format,regreso);//Coloca el formato a la cadena

    gtk_label_set_markup(GTK_LABEL(TabPost), markup);//Colocamos lo que imprimiremos dentro de la respectiva label
    PangoFontDescription *font = pango_font_description_from_string("serif, Normal, 16");//font: tipo de letra y tamaño
    gtk_widget_modify_font(TabPost, font);//Modificamos la etiqueta con el font

    g_free(markup);//Liberamos el markup
}

void Mostrar_Profundidad(int argc, char *argv[]){
    FILE * fichero;
    fichero = fopen("Prof.txt","r");
    fgets(regreso,50,fichero);
    markup = g_markup_printf_escaped(format,regreso);//Coloca el formato a la cadena
    gtk_label_set_markup(GTK_LABEL(TabProf), markup);//Colocamos lo que imprimiremos dentro de la respectiva label
    PangoFontDescription *font = pango_font_description_from_string("serif, Normal, 16");//font: tipo de letra y tamaño
    gtk_widget_modify_font(TabProf, font);//Modificamos la etiqueta con el font

    g_free(markup);//Liberamos el markup
}

void buscar_dato(GtkWidget *widget,GtkWidget *entry){
	gchar *entry_dato;
   
	char buscar[10];
 	entry_dato  = gtk_entry_get_text(GTK_ENTRY(entry));
 	printf("Dato Ingresado: %s\n",entry_dato);//Escrimos los números en consola
        strcpy(buscar,entry_dato);//Copia el elemnto en bu
	Dato=atoi(buscar);//Guarda el elemento entero
        busqueda=Buscar(Arbol,Dato);//Llama la funciónet *widget,GtkWidget *entry
	if(busqueda != 0){
		elem=1;
  		g_print("%s", "El elemento se encontró\n");//Si el elemento se encuentra envia mensaje en consola
  	}else{
  		g_print("%s", "El elemento no se encuentra en el Árbol\n");//Si el elemento no se encuentra en via mensaje a consola 
  		elem=0;
  	}
  	
}


void Elemento_buscado(){
	GtkWidget *ventana, *button,*Button;
	GtkWidget *contenedor, *fondo;
        //Creamos la ventana con sus caracteristicas
	ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(ventana), GTK_WIN_POS_CENTER);
	gtk_window_set_title((GtkWindow *)ventana, "Busqueda");
	gtk_window_set_default_size(GTK_WINDOW(ventana), 300,400);
         if (elem==1){
	fondo = gtk_image_new_from_file("Imagenes/Fondo.jpg");
	}else{
	fondo = gtk_image_new_from_file("Imagenes/Juego.jpg");}
	
        //Creamos botones
	button= gtk_button_new();
	button = gtk_image_new_from_file("Imagenes/Info11.png");//Escogemos imagen para el boton
	gtk_button_set_image (GTK_BUTTON(button),Button);//Colocamos la imagen en el boton
	contenedor = gtk_fixed_new();

	gtk_fixed_put(GTK_FIXED(contenedor), fondo,0,0);//Colocamos el fondeo dentro del contenedor
	gtk_fixed_put(GTK_FIXED(contenedor), button, 30,40);//Colocamos el boton app en el contenedor
	
  gtk_container_add(GTK_CONTAINER(ventana), contenedor);//Añadimos el contenedor a ls ventana
  g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(destroy),(gpointer) contenedor); //Mandamos a llamar el Acerca_App  
  gtk_widget_show_all(ventana);//Mostramos todo lo contenido en la ventana


}


void Buscar_elemento(int argc, char *argv[]){

	//GtkWidget *window;
	GtkWidget *vbox, *hbox;
	GtkWidget *entry;
	GtkWidget *button;

	gtk_init (&argc, &argv);

	//crear una nueva ventana
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_usize( GTK_WIDGET (window), 300, 200);
	gtk_window_set_title(GTK_WINDOW (window), "Buscar dato");
	g_signal_connect(G_OBJECT(Ventana), "destroy", G_CALLBACK (gtk_main_quit), NULL);

  //Creamos una caja vertical
	vbox = gtk_vbox_new (FALSE, 0);
	gtk_container_add (GTK_CONTAINER (window), vbox);
	gtk_widget_show (vbox);//Mostramos la caja

	entry = gtk_entry_new_with_max_length (50);//entrada de maximo 50
	gtk_signal_connect(GTK_OBJECT(entry), "activate",GTK_SIGNAL_FUNC(buscar_dato),entry);//En caso de enter llamamos a la función enter_callback

 //Colocamos la caja de texto en vbox
	gtk_entry_select_region (GTK_ENTRY (entry), 0, GTK_ENTRY(entry)->text_length);
	gtk_box_pack_start (GTK_BOX (vbox), entry, TRUE, TRUE, 0);
	gtk_widget_show (entry);

	hbox = gtk_hbox_new (FALSE, 0);
	gtk_container_add (GTK_CONTAINER (vbox), hbox);
	gtk_widget_show (hbox);

	button = gtk_button_new_with_label ("Buscar");
 	g_signal_connect(GTK_OBJECT (button), "clicked",G_CALLBACK(Elemento_buscado),NULL);
	gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);
	GTK_WIDGET_SET_FLAGS (button, GTK_CAN_DEFAULT);
	gtk_widget_grab_default (button);
	gtk_widget_show (button);

	gtk_widget_show(window);

	gtk_main();
}

void actualizar(){

        FILE *ARCHIVO;
        FILE *fichero;
        char array[50];
        int  dato[50];
        char arreglo[50];
        int i;
        int  aux;
        char vec[50];
                            
        ARCHIVO=fopen("Nodos.txt","r");
        fgets(array,50,ARCHIVO);
        fclose(ARCHIVO);
        puts(array);//muestra los datos que estan en nodos.txt
        sprintf(dato, "%d", Dato);//convierte en entero a caracter
        puts(dato);//imprime el dato que ingresa el usuario
     
     for(i=0;i<10;i++){
     
     if(array[i]==Dato){
     
     aux=Dato;
     
     }else vec[i]=array[i];
     
     }
     puts(vec);

      /* fichero=fopen("Nodos.txt", "w+");
        fputs(vec,fichero);
        fclose(fichero);*/
       
      }
      
    

void Elemento_eliminado(GtkWidget *widget,GtkWidget *entry){
	GtkWidget *dialog;
	GtkWindow *parent_window;
 	dialog = gtk_dialog_new ();
	gint respuesta;
        gchar *entry_dato;
   
	
	if(elem==1)
	{
		  		//dialog nos genera un mensaje en pantalla para aceptar o negar
      	dialog = gtk_message_dialog_new(GTK_WINDOW(window),GTK_DIALOG_DESTROY_WITH_PARENT,  GTK_MESSAGE_QUESTION, 
      	GTK_BUTTONS_YES_NO,"¿Desea eliminar este nodo?  \n");
	  respuesta=gtk_dialog_run(GTK_DIALOG(dialog));
           g_print("la respuesta: %d\n", respuesta);  	
          
          if (respuesta==-8){
          
         actualizar();        
          g_print("elemento eliminado");  	
  	}

    	}
    	}	  	
  	


void Eliminar_elemento(int argc, char *argv[]){

	//GtkWidget *window;
	GtkWidget *vbox, *hbox;
	GtkWidget *entry;
	GtkWidget *button;

	gtk_init (&argc, &argv);

	//crear una nueva ventana
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_usize( GTK_WIDGET (window), 300, 200);
	gtk_window_set_title(GTK_WINDOW (window), "Eliminar dato");
	g_signal_connect(G_OBJECT(Ventana), "destroy", G_CALLBACK (gtk_main_quit), NULL);

  //Creamos una caja vertical
	vbox = gtk_vbox_new (FALSE, 0);
	gtk_container_add (GTK_CONTAINER (window), vbox);
	gtk_widget_show (vbox);//Mostramos la caja

	entry = gtk_entry_new_with_max_length (50);//entrada de maximo 50
	gtk_signal_connect(GTK_OBJECT(entry), "activate",GTK_SIGNAL_FUNC(buscar_dato),entry);//En caso de enter llamamos a la función enter_callback

 //Colocamos la caja de texto en vbox
	gtk_entry_select_region (GTK_ENTRY (entry), 0, GTK_ENTRY(entry)->text_length);
	gtk_box_pack_start (GTK_BOX (vbox), entry, TRUE, TRUE, 0);
	gtk_widget_show (entry);

	hbox = gtk_hbox_new (FALSE, 0);
	gtk_container_add (GTK_CONTAINER (vbox), hbox);
	gtk_widget_show (hbox);

	button = gtk_button_new_with_label ("Eliminar");
 	g_signal_connect(GTK_OBJECT (button), "clicked",G_CALLBACK(Elemento_eliminado),NULL);
	gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);
	GTK_WIDGET_SET_FLAGS (button, GTK_CAN_DEFAULT);
	gtk_widget_grab_default (button);
	gtk_widget_show (button);

	gtk_widget_show(window);

	gtk_main();

	
}


void Mostrar_Arbol(int argc, char *argv[]){
	GtkWidget *PreOrden,*EnOrden,*PostOrden,*Profundidad, *Buscar,*Eliminar;
	GtkWidget *Preorden,*Enorden,*Postorden,*profundidad, *buscar, *eliminar;
	GtkWidget *ContainButt,*ContainAr,*Containinfo,*ContainTo;
  	GtkWidget *ContainImg;
	GtkWidget *MiArbol;
  	GtkWidget *Window;

	gtk_init(&argc,&argv);
  //Creamos la ventana con sus caracteristicas
	Window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(Window),GTK_WIN_POS_CENTER);
	gtk_window_set_title((GtkWindow *) Window, "Mi Árbol");
	gtk_window_set_default_size(GTK_WINDOW(Window), 1000,800);
  //Creamos los botones
	Preorden = gtk_button_new();
	Enorden = gtk_button_new();
	Postorden = gtk_button_new();
	profundidad = gtk_button_new();
	buscar = gtk_button_new();
	eliminar = gtk_button_new();

  //Creamos las etiquetas
  TabPre = gtk_label_new(NULL);
  TabEn = gtk_label_new(NULL);
  TabPost = gtk_label_new(NULL);
  TabProf = gtk_label_new(NULL);
  TabBus = gtk_label_new(NULL);
  TabElim = gtk_label_new(NULL);

	MiArbol = gtk_image_new_from_file("Arbol.png");
	PreOrden = gtk_image_new_from_file("Imagenes/Pre.png");
	gtk_button_set_image(GTK_BUTTON(Preorden),PreOrden);
	EnOrden = gtk_image_new_from_file("Imagenes/En.png");
	gtk_button_set_image(GTK_BUTTON(Enorden),EnOrden);
	PostOrden = gtk_image_new_from_file("Imagenes/Pos.png");
	gtk_button_set_image(GTK_BUTTON(Postorden),PostOrden);
	Profundidad = gtk_image_new_from_file("Imagenes/Prof.png");
	gtk_button_set_image(GTK_BUTTON(profundidad),Profundidad);
	Buscar = gtk_image_new_from_file("Imagenes/buscar.png");
	gtk_button_set_image(GTK_BUTTON(buscar),Buscar);
	Eliminar = gtk_image_new_from_file("Imagenes/En.png");
	gtk_button_set_image(GTK_BUTTON(eliminar),Eliminar); 
  //Creamos contenedores
	ContainButt = gtk_fixed_new();//contenedor para botones
	ContainAr = gtk_fixed_new();//contenedor para el árbol
	Containinfo = gtk_fixed_new();//contenedor para las etiquetas
	ContainTo = gtk_fixed_new();//contenedor universal
  	ContainImg = gtk_fixed_new();//contenedor del ContainAr

  //Guardamos cada widget en su respectivo contenedor
	gtk_fixed_put(GTK_FIXED(ContainAr), MiArbol, 0, 0);
	gtk_fixed_put(GTK_FIXED(ContainButt), Preorden,310, 0);
	gtk_fixed_put(GTK_FIXED(ContainButt), Enorden,310,50);
	gtk_fixed_put(GTK_FIXED(ContainButt), Postorden,310,100);
	gtk_fixed_put(GTK_FIXED(ContainButt), profundidad,310,150);
    gtk_fixed_put(GTK_FIXED(ContainButt), buscar,310,200);
	gtk_fixed_put(GTK_FIXED(ContainButt), eliminar,310,250);
    gtk_fixed_put(GTK_FIXED(Containinfo), TabPre, 410,10);
  	gtk_fixed_put(GTK_FIXED(Containinfo), TabEn, 410,60);
  	gtk_fixed_put(GTK_FIXED(Containinfo), TabPost, 410,110);
  	gtk_fixed_put(GTK_FIXED(Containinfo), TabProf, 410,160);
   	gtk_fixed_put(GTK_FIXED(Containinfo), TabBus, 410,210);
	gtk_fixed_put(GTK_FIXED(Containinfo), TabElim, 410,260);
  //Guardamos los contenedores en el contenedor universal
	gtk_fixed_put(GTK_FIXED(ContainImg), ContainAr,0,0);
    gtk_fixed_put(GTK_FIXED(ContainTo), ContainImg,0,0);
	gtk_fixed_put(GTK_FIXED(ContainTo), ContainButt,300,0);
	gtk_fixed_put(GTK_FIXED(ContainTo), Containinfo,400,0);


  gtk_container_add(GTK_CONTAINER(Window), ContainTo);//Colocamos el contenedor en la Ventana

	gtk_widget_show_all(Window);//Mostramos todos los widgets de la ventana

  g_signal_connect(G_OBJECT(Preorden), "clicked", G_CALLBACK(Mostrar_PreOrden),NULL);//Mandamos a llamar Mostrar_PreOrden
  g_signal_connect(G_OBJECT(Enorden), "clicked", G_CALLBACK(Mostrar_EnOrden),NULL);//Mandamos a llamar Mostrar_EnOrden
  g_signal_connect(G_OBJECT(Postorden), "clicked", G_CALLBACK(Mostrar_PostOrden),NULL);//Mandamos a llamar Mostrar_PostOrden
  g_signal_connect(G_OBJECT(profundidad), "clicked", G_CALLBACK(Mostrar_Profundidad),NULL);//Mandamos a llamar Mostrar_Profundidad
  g_signal_connect(G_OBJECT(buscar), "clicked", G_CALLBACK(Buscar_elemento),NULL);//Mandamos a llamar Buscar_elemento
  g_signal_connect(G_OBJECT(eliminar), "clicked", G_CALLBACK(Eliminar_elemento),NULL);//Mandamos a llamar Buscar_elemento
  g_signal_connect(G_OBJECT(Window), "destroy", G_CALLBACK(destroy_ventana),NULL);

	gtk_main();
}

void Ingresa_Datos(int argc, char *argv[]){

	GtkWidget *window;
	GtkWidget *vbox, *hbox;
	GtkWidget *entry;
	GtkWidget *button;
	GtkWidget *check;

	gtk_init (&argc, &argv);

	//crear una nueva ventana
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_usize( GTK_WIDGET (window), 300, 200);
	gtk_window_set_title(GTK_WINDOW (window), "Ingrese los datos");
	g_signal_connect(G_OBJECT(Ventana), "destroy", G_CALLBACK (destroy_ventana), NULL);

  //Creamos una caja vertical
	vbox = gtk_vbox_new (FALSE, 0);
	gtk_container_add (GTK_CONTAINER (window), vbox);
	gtk_widget_show (vbox);//Mostramos la caja

	entry = gtk_entry_new_with_max_length (50);//entrada de maximo 50
	gtk_signal_connect(GTK_OBJECT(entry), "activate",GTK_SIGNAL_FUNC(enter_callback),entry);//En caso de enter llamamos a la función enter_callback

 //Colocamos la caja de texto en vbox
	gtk_entry_select_region (GTK_ENTRY (entry),
													 0, GTK_ENTRY(entry)->text_length);
	gtk_box_pack_start (GTK_BOX (vbox), entry, TRUE, TRUE, 0);
	gtk_widget_show (entry);

	hbox = gtk_hbox_new (FALSE, 0);
	gtk_container_add (GTK_CONTAINER (vbox), hbox);
	gtk_widget_show (hbox);

	button = gtk_button_new_with_label ("Mostrar Árbol");
  g_signal_connect(GTK_OBJECT (button), "clicked",G_CALLBACK(Mostrar_Arbol),NULL);
	gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);
	GTK_WIDGET_SET_FLAGS (button, GTK_CAN_DEFAULT);
	gtk_widget_grab_default (button);
	gtk_widget_show (button);

	gtk_widget_show(window);

	gtk_main();
}

int main(int argc, char *argv[])
{
  GtkWidget *Cargar,*Acercade,*Salir, *cargar, *acercade, *salir, *Fondo;
  GtkWidget *Container;

  gtk_init(&argc, &argv);

  Ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position (GTK_WINDOW (Ventana), GTK_WIN_POS_CENTER);
  gtk_window_set_title((GtkWindow *) Ventana, "Arboles Binarios");
  gtk_window_set_default_size(GTK_WINDOW(Ventana), 1000, 700);

  cargar = gtk_button_new();
  acercade = gtk_button_new();
  salir = gtk_button_new();

  Fondo = gtk_image_new_from_file("Imagenes/Fondo1.jpg");
  Cargar = gtk_image_new_from_file("Imagenes/Cargar1.png");
  gtk_button_set_image(GTK_BUTTON(cargar), Cargar);
	Acercade = gtk_image_new_from_file("Imagenes/Info1.png");
  gtk_button_set_image(GTK_BUTTON(acercade), Acercade);
	Salir = gtk_image_new_from_file("Imagenes/Salir.png");
  gtk_button_set_image(GTK_BUTTON(salir), Salir);


  Container = gtk_fixed_new();

  gtk_fixed_put(GTK_FIXED(Container), Fondo, 0, 0);
  gtk_fixed_put(GTK_FIXED(Container), cargar,590, 550);
  gtk_fixed_put(GTK_FIXED(Container), acercade,260,320);
  gtk_fixed_put(GTK_FIXED(Container), salir,760,380);
  gtk_container_add(GTK_CONTAINER(Ventana), Container);

  g_signal_connect(G_OBJECT(cargar), "clicked", G_CALLBACK(Ingresa_Datos), (gpointer) Container);
  g_signal_connect(G_OBJECT(acercade), "clicked", G_CALLBACK(Acerca_de), (gpointer) Container);
  g_signal_connect(G_OBJECT(salir), "clicked", G_CALLBACK(destroy), (gpointer) Container);

  gtk_widget_show_all(Ventana);
  g_signal_connect(G_OBJECT(Ventana), "destroy", G_CALLBACK (gtk_main_quit), NULL);

  gtk_main();
}









