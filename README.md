# EmissionChecked: Program Penyedia Klasifikasi Kualitas Emisi Gas Buang pada Sektor Industri

## Penulis
- Ivan Indirsyah Pahlevi (2006574332)
- Ricky Rahman Papudi (2006574282)
- Rifqi Annas Albasyahri (2006574370)

## Tujuan
Mengklasifikasikan kualitas emisi gas buang dari dari sektor industri sesuai dengan standarisasi Kementerian Lingkungan Hidup dan Kehutanan (KLHK).

## Latar Belakang
Emisi gas pada dasarnya menjadi salah satu permasalahan utama yang terjadi di Indonesia. Pada tahun 2015, sebuah studi melaporkan suhu bumi naik antara 1,5° hingga 2° Celcius dibandingkan masa pra-industri. Selain itu, Menurut hasil penelitian lainnya, es Samudra Arktik terus mencair sehingga permukaan air laut semakin tinggi setiap tahun. Ada pula riset yang menunjukkan bahwa air dari Samudera Atlantik	sudah naik ke Samudera Arktik. Oleh karena itu, Perjanjian Paris yang dilahirkan Conference of the Party (COP)	ke-21 pada Desember 2015 dilaksanakan sebagai salah satu upaya untuk mencegah perubahan iklim yang terjadi.	Partisipasi Indonesia dalam hal ini adalah menetapkan 4 target utama, yaitu menjaga kenaikan temperatur global	di bawah 2°C dan mengupayakan kenaikan temperatur global 1,5°C; Emisi Netto Nol (net-zero emission)	sebagai tujuan jangka panjang; komitmen untuk membatasi emisi gas rumah kaca melalui Nationally Determined Contribution (NDC); dan terakhir, Global Stocktake secara berkala. Akan tetapi, sepanjang 2019, perusahaan energi masih menjadi penyumbang	emisi gas rumah kaca (GRK) terbesar (45.7% selain sektor hutan dan penggunaan lahan). Sub sektor pembangkitan listrik	bertanggung jawab terhadap 35% emisi GRK, diikuti oleh transportasi dan industri masing-masing 27%. Hingga tahun 2020,	sektor ketenagalistrikan Indonesia tetap didominasi oleh bahan bakar fosil (82%), dengan batubara menyumbang pangsa tertinggi (62%) dalam pembangkitan listrik di tahun 2020. Akibatnya intensitas emisi sektor ketenagalistrikan selama lima tahun dari 2015-2020 tidak mengalami perubahan signifikan (hanya menurun sebesar 1%). Padahal, rata-rata negara anggota G20 telah menurun 10 kali lebih cepat.  Permasalahan emisi di indonesia bisa terjadi karena beberapa faktor seperti pemerintah yang kurang memiliki data terintegrasi mengenai informasi perusahaan mana saja yang harus dijadikan prioritas untuk dikurangi emisinya. Selain itu, permasalahan mungkin juga terjadi karena tidak adanya transparansi data mengenai informasi tersebut oleh sebagian perusahaan industri.	Oleh karena itu, kelompok kami menciptakan sebuah program yang dapat mengklasifikasikan kualitas emisi gas buang dari sektor industri	yang nantinya dapat dijadikan sebagai salah satu cara untuk mengawasi/memantau kinerja perusahaan dalam mengurangi emisinya.

## Deskripsi
Program yang kelompok kami buat merupakan program yang dibangun menggunakan bahasa C. Program ini merupakan program yang berbasis data struktur dimana data disimpan dalam array dengan sistem linked list. Data dalam satu array menggunakan sistem struct dimana dalam satu struct tersebut berisi data berupa nama perusahaan, kualitas emisi perusahaan, level emisi perusahaan, dan kelompok perusahaan yang berdasar pada emisi yang dihasilkan dari perusahaan. Program Kami juga akan menggunakan berbagai kriteria yang telah ditetapkan, yaitu
	
## Fungsi
Program yang kelompok kami buat akan memiliki beberapa fungsi. fungsi pertama adalah fungsi void yang tidak menurut apapapun, fungsi tersebut akan digunakan untuk memasukkan data perusahaan, termasuk nama, komponen dari parameter emisi gas buang seperti CO, CO2, dan lain - lain. Selain itu fungsi void juga digunakan untuk menampilkan data perusahaan beserta komponen parameter, mencari perusahaan dengan data masukan tertentu, dan mengurutkan perusahaan berdasarkan parameter emisi yang akan ditentukan oleh user. Fungsi selanjutnya yang digunakan adalah fungsi yang akan mereturn nilai. Fungsi tersebut akan digunakan sebagai fungsi untuk melakukan perhitungan	standar kelayakan suatu perusahaan berdasarkan pada parameter yang sebelumnya telah diinputkan yaitu parameter dari emisi gas buang perusahaan.

## Fitur
- User Friendly
Program kami akan menyediakan panduan bagi user agar meminimalisir keambiguan saat menjalankan program. Kami juga akan mengelompokkan variabel - variabel yang akan digunakan pada program berdasarkan kategori tertentu untuk memudahkan programmer lainnya melanjutkan program yang akan kami buat. Pada bagian user interface kita juga akan membuat page welcome pada pengguna dan	memberikan informasi apabila user salah memasukkan input.
	
- Header File
Program kami akan mengklasifikasikan function berdasarkan kategori-kategori tertentu dan menyimpannya dalam header file yang terpisah untuk memudahkan pembagian tugas dan pengecekan apabila terjadi error pada program.
	
- Function Prototype
Program kami menyediakan prototipe fungsi dalam masing-masing header file untuk mendeklarasikan data type dan jumlah argumen yang diberikan dalam suatu function.
	
- Rekursi
Program yang kami buat, akan terdiri dari satu fungsi rekursi yang spesifik menghitung rata - rata dari kandungan gas emisi yang terdapat pada data perusahaan.
	
- Array 1D
Array 1D akan digunakan sebagai variabel untuk menyimpan nama perusahaan dengan aturan, index 0 untuk perusahaan a, index 1 untuk perusahaan b, index 2 untuk perusahaan c, dan seterusnya.
	
- Array 2D:
Array 2D akan digunakan untuk menyimpan data dari parameter yang akan dihitung dari emisi gas yang dihasilkan oleh tiap perusahaan. Misalnya, data[index1][index2], index 1 digunakan untuk data dari perusahaan misalnya index1 = 0, maka perusahaan A dan index2 akan menyimpan data dari parameter emisi gas yang akan diamati misalnya index2 = 0, gas A.

- Binary Tree
Binary tree juga kami gunakan untuk melakukan beberapa operasi, seperti operasi penampilan data perusahaan, dan operasi pencarian data perusahaan.

- Linked List
Linked list digunakan untuk penampilan data perusahaan, pencarian data perusahaan, serta penambahan dan penghapusan data perusahaan.

- Searching
Program kami akan menggunakan searching dalam mencari data menggunakan tag key search tertentu, seperti nama perusahaan dan hasil klasifikasi kualitas emisi gas buang. Kami akan menggunakan beberapa algoritma pencarian berdasarkan parameter yang akan dicari dari data perusahaan. Untuk nama perusahaan kami akan mencari menggunakan algoritma linear, sedangkan untuk parameter lainnya akan menggunakan algoritma seperti binary search untuk meminimalkan proses komputasi.

- Sorting
Program kami akan menggunakan sorting dalam mengurutkan data berdasarkan abjad nama perusahaan dan hasil klasifikasi emisi gas buang. Kami akan menggunakan beberapa algoritma dari melakukan sorting berdasarkan dari parameter yang akan diurutkan. Untuk mengurutkan data perusahaan berdasarkan abjad, maka kami akan menggunakan metode bubble sort dimana metode ini efektif untuk data kecil seperti inisial awal nama perusahaan. Untuk parameter lainnya, kami akan mempertimbangkan algoritma pengurutan seperti insertion sort maupun binary sort.
