#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
class Matris{
public:
    void dosyaAl();
    double xsobel(short int **goruntu,int x,int y);
    double ysobel(short int **goruntu,int x,int y);
    int threeshold(double sayi);
protected:
    int row;
	int col;
	short int **goruntu;
};
class Img:public Matris{
public:


protected:

};


int main()
{

    Matris m;
    m.dosyaAl();

    return 0;
}
void Matris::dosyaAl(){
    ifstream dosya;
	dosya.open("image2.bin", ios::in | ios::binary);
	char buffer[44003];
	dosya.clear();
	string s;
	if (!dosya.is_open())
		cout << "Dosya acilamadi!" << endl;
	else {
		dosya.read(buffer, 44002);
		buffer[44003] = '\0';
        row=int(buffer[0]) + 256 ;
        col=int(buffer[1]) + 256;
		//Matris m(rc,cc);
		//col=col-20;
		goruntu = new short int*[row];
      for(int i=0;i<row;i++){
        goruntu[i] = new short int[col];
      }
   int q=2;
		for(int i=0;i<col;i++){
         for(int j=0;j<row;j++){
			if (int(buffer[q]) < 0) {
				goruntu[j][i] = int(buffer[q]) + 256 ;
				//cout<<int(buffer[q]) + 256 ;
				//s += char(int(buffer[q])+256);
			}
			else
			{
			   // cout<<int(buffer[q]) ;
				goruntu[j][i] = int(buffer[q]);
				//s += char(int(buffer[q]));
			}
         q++;
        }
      }
	}
	for(int i=1;i<row-1;i++){
        for(int j=1;j<col-1;j++){
         /* double xs=xsobel(goruntu,i,j);
          double ys=ysobel(goruntu,i,j);
          double sum=sqrt(abs(xs)+abs(ys));
          goruntu[i][j]=threeshold(sum);*/
        }
      }
      fstream dosya3;
      dosya3.open("sonuc.txt", ios::out);
      for(int i=1;i<row-1;i++){
        for(int j=1;j<col-1;j++){
           if(goruntu[i][j]<100)
            dosya3<<"+";
           else
            dosya3<<"-";
        }
        dosya3<<"\n";
      }
}
double Matris::xsobel(short int **goruntu,int x,int y){
    return goruntu[x-1][y+1] +
                2*goruntu[x-1][y] +
                 goruntu[x-1][y-1] -
                  goruntu[x+1][y+1] -
                   2*goruntu[x+1][y] -
                    goruntu[x+1][y-1];
}
double Matris::ysobel(short int **goruntu,int x,int y){
    return goruntu[x-1][y-1] +
                2*goruntu[x][y-1] +
                 goruntu[x+1][y-1] -
                  goruntu[x-1][y+1] -
                   2*goruntu[x][y+1] -
                    goruntu[x+1][y+1];
}
int Matris::threeshold(double sayi){
    if(sayi>=100)
        sayi=1;
    else
        sayi=0;
    return sayi;
}
