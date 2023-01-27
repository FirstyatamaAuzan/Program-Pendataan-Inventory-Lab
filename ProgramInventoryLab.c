#include<stdio.h>
#include<string.h>//strlen
#include <stdlib.h>	
#define true 0 //true boolean
#define false 1 // for  false the boolean


	struct product
	{
		char id[10];   // product code/no.
		char name[20]; // product name
		int quantity; // remaining quantity of product. Subtract from the original quantity the quantity purchased
        int barangrusak;
	};
	struct product prod[30];//the maximum array elements.
	int count = 0;	// this will be incremented if there is a new product and this is the 
 	FILE *f;	//for the file pointer

 	int writefile()//write file function
{
    
    int i;
    f = fopen("inventoryLAB.txt", "w");  // ayaw i append; change from f = fopen("inventory.txt", "a");
    if (f == NULL)
        return -1;			
    fprintf(f, "%d\n", count);
    for (i = 0; i < count; ++i) // writing all the details from all the function to the text file.
    {
        // Changed
        fputs(prod[i].id, f);
        fprintf(f, "\n");
        fputs(prod[i].name, f);
        fprintf(f, "\n");
       fprintf(f, "%d\n", prod[i].quantity);
        fprintf(f, "%d\n", prod[i].barangrusak);
        
    }
    fclose(f);
    return 0;
}
int readFile() // read file function
{
    int n = 0;
    int i;
    f = fopen("inventoryLAB.txt", "r");
    if (f == NULL)
        return -1;
    fscanf(f, "%d\n", &n);
    for (i = 0; i < n; ++i)
    {
        fgets(prod[i].id, 10, f);
        prod[i].id[strlen(prod[i].id) - 1] = 0; // remove new lines
        fgets(prod[i].name, 20, f);
        prod[i].name[strlen(prod[i].name)-1] = 0; // remove new lines
         fscanf(f, "%d", &prod[i].quantity);
        fscanf(f, "%d\n", &prod[i].barangrusak);
        
        
    }
    fclose(f);
    return n;
}

void deleteprod(){ //function for the delete product. 
	count=readFile();
	char id[10]; 
	int i,j;
	int z=false;
printf("masukkan ID barang yang ingin dihapus : "); //user's input for deleting.
fflush(stdin);
gets(id);

for(i=0;i<count;i++){		//loop to finding the user's input
		z=true;
	if(strcmp(prod[i].id,id)==0){ // if the user's input matched the data
	for( j=i; j<(count-1); j++)	// it will erase the selected data.
			{
				prod[j]=prod[j+1];
			}
			count--;
	}
}
if(z==false){	// will be executed if the product id is not available.
	printf("tidak dapat menemukan id barang: %s .",id);
}
writefile();
}

int IDChecker(int i, int j)	//checking the input id
{
	count=readFile();
    printf("ID barang: ");
    fflush(stdin);
	gets(prod[count].id);
    if (strcmp(prod[i].id,prod[j].id)==0){
        printf("nomor ID telah digunakan");
        return IDChecker(i++,j--);
		}
}


void addProd(){	// function to add products to the file 

  	printf("\nMASUKKAN BARANG BARU\n");
	readFile();		//reading the files .
  	    if (count>0) {
  	    count=readFile();
  		IDChecker(0,count); // to check if the id is already used.
		}
	else{
		printf("\nNomor ID Barang: ");
		fflush(stdin); 
		gets(prod[count].id);
		}
		printf("Nama Barang: ");gets(prod[count].name);
		printf("Jumlah Barang Tersedia: ");scanf("%d",&prod[count].quantity);
        
		++count; // increment count for the product positions and how many are they in the array.

	writefile(); // putting/saving this to the file.
}


int checkID(char id[]){ // checking the id if available
	int i;
count=readFile();

	
 		readFile();
 		for(i=0;i<count;i++){
		 
	if(strcmp(id,prod[i].id)!=0){ //if the id and data id doesnt match.
		
			 fclose(f);
		}
   return 1;		// returning an error.
  }
	
 fclose(f);
 return 0; // return 0 if no error.
}


void editProd(){	//Editing the product function
	char id[10];
int test;
int i;
	int choice;
  printf("EDIT BARANG!");
  printf("\nMasukkan nomor ID Barang yang akan di edit: "); // users input for what data will be change
	fflush(stdin);
	gets(id);
	test=checkID(id);
    if (test == 0)
 {
  printf("ID dengan nomor %s tidak ditemukan.", id); // if the data is empty
 }
 else
 {
 		readFile();
  {
	for(i=0;i<count;i++){
	
  if(strcmp(id,prod[i].id)!=0) // if the data is not empty 
	writefile();
   else
   {
    printf("\n1. Update Nomor ID barang?");
    printf("\n2. Update Nama Barang? ");
    printf("\n3. Update jumlah barang tersedia?");
    
    
    printf("\nketik nomor yang dipilih:");
    fflush(stdin);
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
    
     printf("Masukkan ID Baru: ");
 		fflush(stdin);
        gets(prod[i].id);
     break;
    case 2:
     printf("Masukkan Nama baru: ");
    	fflush(stdin);
        gets(prod[i].name);
     break;
    case 3:
     printf("Masukkan Jumlah barang tersedia: ");
    scanf("%d",&prod[i].quantity);
    break;
    
    default:
     printf("Invalid Selection");
     break;
    }
   writefile();
   }
   
   }
  }
  fclose(f); 
  f = fopen("InventoryLAB.txt", "r");
 readFile();
 {
   writefile();
  }
  fclose(f);
  printf("\n PERUBAHAN TELAH DISIMPAN");
 }
}


void displayprod(){
	int i=0;

  count = readFile(); // the output is how many products inside the file.
  if (count < 0)
    puts("cannot open file");
	printf(" \t\t *****  INVENTORY *****\n");
   printf("--------------------------------------------------------------------\n");
   printf("NO. |    NAMA     |  ID BARANG  | BARANG TERSEDIA  |  BARANG RUSAK  |\n");
   printf("--------------------------------------------------------------------\n");

   for (i=0;i<count;i++){ // getting the details on each product updates.
   printf("%d       %-10s       %-8s         %-5d           %-3d\n", i+1, prod[i].name, prod[i].id, prod[i].quantity, prod[i].barangrusak);
	}

}


void barangbroken(){// function for purchasing a product 
	int quant;
    int i;
    char id[10];
    int z=false;
    count=readFile();
	printf("input jumlah barang rusak ");
    printf("\nNomor ID Barang: ");
    fflush(stdin);
	gets(id);
    for (i=0; i<count; i++){
        if (strcmp(id,prod[i].id)==0) 	// if the id that the user want to find and the data id that has been saved at file is matched.
        {
        	z=true;
        printf("\nbarang ditemukan: \n");//...then display the match
	   	printf("\nProduct name: %s",prod[i].name);
		printf("\nproduk masih layak pakai saat ini: %d",prod[i].quantity);
        printf("\n produk rusak saat ini: %d\n\n",prod[i].barangrusak);
	
            printf("ketikkan jumlah barang yang rusak  : ");
            fflush(stdin);
			scanf("%d",&quant);
            if (quant>prod[i].quantity){		// if the quantity is lessthan the users quant
               puts("\njumlah barang rusak yang anda inputkan \n melebihi barang yang masih layak pakai saat ini\n ");
             break; // break and back to the choices.
				}
           
               // will be executed if the quantity is greater than the users selected quantity.
            prod[i].barangrusak += quant;
            prod[i].quantity -= quant;
            
			}
	
	}
 if(z==false){	//if the product id is not available.
 
	printf("Cant find the product id: %s.",id);
}
	writefile();


}



	

void caribarang(){
     count=readFile();
     char name[20];
     char id[10];
     int i;
     int z=false;
     int pilihan;
     int test;
printf("\n cari barang : ");
printf("\n 1.) berdasarkan id barang");
printf("\n 2.) berdasarkan nama barang");
 printf("\n ketikkan pilihan: ");
fflush(stdin);
    scanf("%d", &pilihan);

    switch (pilihan)
{
    case 1:
 
 printf("ketikkan Id barang yang dicari: "); //user's input for deleting.
fflush(stdin);
gets(id);

for(i=0;i<count;i++){		//loop to finding the user's input
		z=true;
if(strcmp(prod[i].id,id)==0){
    printf("Nama barang: %s \nID Barang: %s \nJumlah Barang Tersedia: %d \nJumlah barang Rusak: %d \n\n\n",prod[i].name,prod[i].id,prod[i].quantity,prod[i].barangrusak);
}}
if(z==false){	// will be executed if the product id is not available.
	printf("Cant find product id: %s .",id);
}
break;
    case 2:printf("ketikkan nama barang yang dicari: "); //user's input for deleting.

fflush(stdin);
gets(name);

for(i=0;i<count;i++){		//loop to finding the user's input
		z=true;
if(strcmp(prod[i].name,name)==0){
    printf("Nama barang: %s \nID Barang: %s \nJumlah Barang Tersedia: %d \nJumlah barang Rusak: %d \n\n\n",prod[i].name,prod[i].id,prod[i].quantity,prod[i].barangrusak);
}}
if(z==false){	// will be executed if the product id is not available.
	printf("Cant find product id: %s .",name);
}
}
writefile();
}






int main (){
	int choice;
	count = readFile(); // ihapa una pila imong products
	if(count < 0) // there is no file located.
		printf("Cannot locate file\n");
do {
	printf("\n");
	printf("\t\t\t  ================================\n");
	printf("\t\t\t     PRODUCT INVENTORY PROGRAM\n");
	printf("\t\t\t  ================================");

	printf("\n\nPress:");
	printf("\n 1.) Input barang baru");
    printf("\n 2.) input jumlah barang rusak");
	printf("\n 3.) Edit barang");
	printf("\n 4.) Hapus Barang");
	printf("\n 5.) Tampilkan semua barang");
    printf("\n 7.) cari barang dengan id");
	printf("\n 8.) keluar .");
	printf("\nChoice--> ");
	scanf("%d", &choice);
	     switch(choice){
        case 1 :  //add product
                addProd();
                break;
        case 2: // input jumlah barang rusak
                barangbroken();
                break;
        case 3://edit data product
		    	editProd();
				break;
        case 4://delete a product
        deleteprod();
               	 break;
        case 5: //display the products
               displayprod();
                break;
        case 6:
        caribarang();
        break;
        case 7:
		 	  exit(1);
			   break;
		 default :
                printf("Your choice is wrong please try again");
            break;
      }
  }while(choice!=7); // infinite loop until the user will choose number8 .
  printf("Thankyou for using this program");
  
}