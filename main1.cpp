#include<iostream>
#include<exception>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<ctype.h>
#include<fstream>
#include<sstream>
#include"class.h"

using namespace std;

void TestComplexVector(){
	CComplexVector **m;
	ComplexNumber *cn;
	int count=0, type, lg, l=0, im, re,k1,k2,k3; FILE *f;
	char FileName[512], *sss,*s4,*cnum,sign,i1;
	//check this!
	ifstream in0("in.txt"); 
	string str0;\
	//ss >> count;
	//cout<<count;
	while(getline(in0,str0)){count++;}
	in0.close();
	//cout<<count<<endl;
	m=new CComplexVector*[count];
	ifstream in("in.txt"); 
	string str;
	//stringstream ss(str);	
	while(getline(in,str)){
		int Type=1, num=0,i=0; string outfile; //vector<ComplexNumber> vectmp;
		stringstream ss(str);
		ss >> Type >> outfile >> num;
		//cout<< Type << outfile << num <<endl;
		ComplexNumber *vectmp=new ComplexNumber[num];
		for(ComplexNumber tmp;ss >> tmp, i<num; i++){\
			vectmp[i]=tmp;
			//ComplexNumber(tmp);
		}
		m[l]=CComplexVector::create(Type,vectmp,num);
		m[l]->show(outfile.c_str());
		
		l++;
		delete[]vectmp;
	}
	/*f=fopen("in.txt", "r");
	fgets(str,512,f);
	sscanf(str,"%d",&count);
	m=new CComplexVector*[count];
	for(int j=0; j<count && fgets(str,512,f)!=NULL; j++){
		//type - тип вектора
		sscanf(str,"%d%n",&type,&l); 
		ss=str+l;
		while(isspace(*ss))ss++; 
		sss=ss;
		for(lg=0;*ss;lg++,ss++){if(!isalnum(*ss) && *ss!='.' && *ss!='_') break;}
		strncpy(FileName,sss,lg);
		s4=ss;
		for(lg=0;*s4;s4++){if(isspace(*s4))lg++;while(isspace(*s4))s4++;}
		cn=new ComplexNumber[lg];
		cnum=ss;
		for(int i=0; i<lg; i++){
			while(isspace(*cnum))cnum++;
			if(sscanf(cnum,"%d%n",&re,&k1)==1){
				cnum=cnum+k1;
				if(isspace(*cnum) || *cnum=='\0'){
					cn[i].SetRe(re);
				}
				else if(*cnum=='i'){
					cnum=cnum+1;
					cn[i].SetIm(re);
					continue;
				}
				else{
					if(sscanf(cnum,"%d%n",&im,&k2)==1){
						cnum=cnum+k2;
						if(sscanf(cnum,"%c%n",&i1,&k3)==1 && i1=='i'){
							cnum=cnum+k3;
							cn[i].SetRe(re);
							cn[i].SetIm(im);
						}
					}
					else if(sscanf(cnum,"%c%n",&sign,&k2)==1){
						cnum=cnum+1;
						cn[i].SetRe(re);
						if(sign=='+'){
							if(sscanf(cnum,"%c%n",&i1,&k2)==1){
								cnum=cnum+1;
								if(i1=='i'){
									cn[i].SetIm(1);
								}
							}
						}
						else if(sign=='-'){
							if(sscanf(cnum,"%c%n",&i1,&k2)==1){
								cnum=cnum+1;
								if(i1=='i'){
									cn[i].SetIm(-1);
								}
							}
						}
					}
				}
			}
			else if(sscanf(cnum,"%c%n",&sign,&k2)==1){
				cnum=cnum+1;
				if(sign=='-'){
					if(sscanf(cnum,"%c%n",&i1,&k3)==1){
						cnum=cnum+1;
						if(i1=='i'){
							cn[i].SetRe(0);
							cn[i].SetIm(-1);
						}	
					}
				}
				else if(sign=='i'){
					cn[i].SetRe(0);	
					cn[i].SetIm(1);
				}
			}
		}
		m[j]=CComplexVector::create(type,cn,lg);
		m[j]->show(FileName);
		delete[] cn;		
	}*/
	for(int j=0;j<count;j++){delete m[j];}
	delete [] m; m=NULL; 
	//fclose(f);
	in.close();
	}	

int main() {
	try{
		TestComplexVector();
	}catch(exception &err){
		cout << err.what() << endl;
	}
	return 0;
}
