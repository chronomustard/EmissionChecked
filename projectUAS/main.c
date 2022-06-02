#include <stdio.h>
#include <stdlib.h>
#include "FUNC(1).h"

void prosedur();

int main()
{
	int condition = 1, keluar;
	int sorting, searching, menu;
	char dicari[100], namaperus[100], hapusperus[100];
	char rating;
	int initial, back;
	float inputavgComp;
	
	while (initial != 1)
	{
		printf("%70s\n", "WELCOME TO EMISSIONCHECKED PROGRAM");
		printf("%59s\n", "By KELOMPOK 3");
		printf("\n\n\n\n\n\n\n");
		printf("%72s\n%50s", "Press 1 (If you want to start program)", "");
		scanf("%d", &initial);
		if (initial == 1)
		{			
			system("cls");
			break;
		} 
		else
		{
			system ("cls");
			printf("%62s", "Incorrect. Try Again\n\n\n");
		}
	}
	
	// initialization programs
	printCompany();
   	categorizeComp();
  	rateComp();
   	initBinTree();
   	intiLinkedList();
   	
	while (condition == 1)
	{
		printf("\nMenu Pilihan");
        printf("\n\t1. Tampilkan Data perusahaan dengan Array");
        printf("\n\t2. Tampilkan Data perusahaan dengan BinaryTree");
        printf("\n\t3. Tampilkan Data perusahaan dengan LinkedList");
        printf("\n\t4. Urutkan Data Perusahaan berdasarkan Array");
        printf("\n\t5. Cari Data Perusahaan Array");
        printf("\n\t6. Cari Data Perusahaan BinaryTree");
        printf("\n\t7. Cari Data Perusahaan LinkedList");
        printf("\n\t8. Menambah Data Perusahaan dengan LinkedList");
        printf("\n\t9. Menghapus Data Perusahaan dengan LinkedList");
        printf("\n\t10. Prosedur Penggunaan Aplikasi");
        printf("\n\t11. Exit Program");
        printf("\nPilihan : ");
        scanf("%d", &menu);
		switch(menu){
			//Menampilkan Data-Data Perusahaan dengan Array
            case 1 :
            	system("cls");
    			viewAll();
				break;
            case 2 :
            	system("cls");
    			showBinTree();
				break;
            case 3 :
            	system("cls");
    			showLinkedData();
				break;
			//Mengurutkan Data Perusahaan dengan 2 pilihan yaitu ascending atau descending
            case 4 :
            	system("cls");
            	printf("\nPengurutan berdasarkan: ");
        		printf("\n\t1. Ascending");
        		printf("\n\t2. Descending");
        		printf("\nPilihan: ");
        		scanf("%d", &sorting);
				if (sorting == 1)
				{
					printf("\nSorting Ascending\n");
    				sortAscentComp();
    				viewAll();
				} else //if sorting = 2
				{
					printf("\nSorting Descending\n");
					sortDescentComp();
					viewAll();
				}
                break;
            //Mencari Data Perusahaan dengan 2 pilihan parameter yaitu nama atau rating
            case 5 :
            	system("cls");
                printf("\nCari Data Perusahaan Berdasarkan : \n");
                printf("\t1. Nama Perusahaan\n");
                printf("\t2. Kategori\n");
                printf("\nPilihan: ");
                scanf("%d", &searching);
                if(searching == 1)
                {
                    printf("Masukkan Nama Dicari : ");
                    scanf(" %255[^\n]s", &dicari);
                    searchName(dicari);
                }
                else
                {
                    printf("Masukkan Kategori Dicari (A/B/C/D): ");
                    scanf(" %255[^\n]s", &rating);
                    searchValue(rating);
                }
                break;
            case 6 :
            	system("cls");
            	printf("Masukkan Company Average Emission yang ingin dicari (dalam Float): ");
            	scanf("%f", &inputavgComp);
            	printf("\n");
            	searcAveBinTree(inputavgComp);
				printf("Apakah ingin keluar? (Klik 1 untuk Ya): ");
				scanf("%d", &keluar);
				if (keluar == 1){
					system("cls");
				}
				break;            	
            case 7 :
            	system("cls");
            	printf("Masukkan Nama Company: ");
            	scanf(" %255[^\n]s", &namaperus);
            	searchNameLinked(namaperus);
                break;
            case 8 :
            	system("cls");
                printf("\n\nAdd Data Perusahaan : \n\n");
    			addDataLinked();
                break;
            case 9 :
            	system("cls");
            	printf("Masukkan Nama Perusahaan yang ingin Dihapus: ");
            	scanf(" %255[^\n]s", &hapusperus);
                hapusCompany(hapusperus);
                break;
            case 10 :
            	system("cls");
                prosedur();
                break;
            case 11 :
                condition = 0;
                break;
            default :
            	system("cls");
            	printf("Incorrect Input. Try Again.");
                break;
        }   
	}
    return 0;
}

void prosedur()
{
    printf("\t\t====== PENJELASAN TATA CARA DAN PROSEDUR EMISSIONCHECKED PROGRAM ======\n\n\n");
	printf("Pada program EmissionChecked terdapat 5 menu pilihan yaitu: ");
	printf("\n1. Tampilkan Data Perusahaan \n2. Urutkan Data Perusahaan \n3. Cari Data Perusahaan \n4. Prosedur Penggunaan Aplikasi \n5. Exit Program");
	printf("\n\n>>> Menu 1 : \"Tampilkan Data Perusahaan\" \nMenu ini digunakan untuk menampilkan data perusahaan yang telah dimasukkan dalam txt yang dalam hal ini inputnya berasal dari sensor.");
	printf("\n> Cara Penggunaan: \nMasukkan angka 1 pada Menu pilihan -> Output akan mengeluarkan Data");
	printf("\n\n>>> Menu 2 : \"Urutkan Data Perusahaan\" \nMenu ini digunakan untuk mengurutkan perusahaan sesuai dengan tingkat emisi yang tercatat dengan pilihan ascending dan Descending");
	printf("\n> Cara Penggunaan: \nMasukkan angka 2 pada Menu pilihan -> Masukkan angka 1 untuk Ascending dan angka 2 untuk Descending -> Output akan mengeluarkan data sekaligus dengan data-data input gas yang dimasukkan");
	printf("\n\n>>> Menu 3 : \"Cari Data Perusahaan\" \nMenu ini digunakan untuk mencari data perusahaan berdasarkan nama perusahaan atau rating");
	printf("\n> Cara Penggunaan: \nMasukkan angka 3 pada Menu pilihan -> Masukkan angka 1 untuk berdasarkan nama perusahaan dan angka 2 untuk berdasarkan rating \n-> Apabila memilih 1 maka user akan diminta untuk memasukkan nama perusahaan, apabila memilih 2 maka user akan diminta untuk memasukkan a/b/c/d (A memiliki tingkat emisi yang paling baik)");
	printf("\n\n>>> Menu 4 : \"Prosedur Penggunaan Aplikasi\" \nMenu ini digunakan untuk menampilkan prosedur/tata cara menggunakan program ini.");
	printf("\n> Cara Penggunaan: \nMasukkan angka 4 pada Menu pilihan -> Program akan menampilkan seluruh prosedur dan penjelasan program ini");
	printf("\n\n>>> Menu 5 : \"Exit Program\" \nMenu ini digunakan untuk mengakhiri program EMISSIONCHECKED");
	printf("\n> Cara Penggunaan: \nMasukkan angka 5 pada Menu pilihan -> Program akan keluar\n");
}
