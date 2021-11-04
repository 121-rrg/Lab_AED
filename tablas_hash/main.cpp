/*
INTEGRANTES:

* GUTIERREZ ARRATIA RONALD ROMARIO
* CASTILLON URQUIZA LEVI JOEl
* HUMPIRI vALDIVIA FREDDY LEONEL
FECHA: 03/11/2021
*/



#include<iostream>
#include <fstream>
#include <vector>
#include <fstream>
#include "avl.cpp"
#include "lista.cpp"


using namespace std;

unsigned int edit_distance(const string& s1, const string& s2)
{
    const size_t len1 = s1.size(), len2 = s2.size();
    vector <vector <unsigned int>> d(len1 + 1, vector <unsigned int >(len2 + 1));
    d[0][0] = 0;
    for(unsigned int i = 1; i <= len1; ++i) d[i][0] = i;
    for(unsigned int i = 1; i <= len2; ++i) d[0][i] = i;

    for(unsigned int i = 1; i <= len1; ++i)
        for(unsigned int j = 1; j <= len2; ++j)
            d[i][j] = min(min(d[i - 1][j] + 1, d[i][j - 1] + 1), (d[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1)));
    return d[len1][len2];
}

template<class O, class K,  int (*fd)(string ,int),const int size = 194443> // numero primo mas cercano al ultimo

class Hash
{
   private:
      AVLTree<O>  m_arbol[size];
   public:
       Hash(){};
       void Add(O obj, K key)
       { 
           int pos = fd(key,size);
           cout<<"Se inserto elemento en la posicion:"<<pos<<endl;
           m_list[pos].insert(obj); 
           
       }
};


int fd1(string   key, int n)
{
    int s=0;
    char * k = (char*)key.c_str();
    while(*k)
    {
      s+=int(*k);
      k++;   
    }
    return s%n;
}

template<class Tipo>
bool find_h(Tipo &_valor)
{
   if(Tabla.find(_valor)==false)
   {
	    return 0;
   }
   else
   {
     	return 1;
   }
}

template<class Tipo>
bool _delete(Tipo &_valor)
{
   int pos = Hash(_valor);

   if(Tabla.Quitar(_valor))
   {
      return true;
   }
   else
   {
      return false;
   }

}

template<typename T>
void comparar(Lista<T> mylist , Hash<T,T,fd1> Tabla ){
    Elemento<T> *actual = mylist.Primero;
    Elemento<T> *actual2 = mylist.Primero;
    int cont = 0;
    while(actual->Sig!=nullptr){
        Tabla.Add(string(actual->valor),string(cont));
        while(actual2->Sig!=nullptr){
            if(edit_distance(actual,actual2)<=3){
                Tabla.Add(string(actual2->valor),string(cont));
                mylist.Quitar(actual2->valor);

            }  
        }
        cont++;
    }
}

int main()
{
    Hash<string, string, fd1> Tabla;
    
    Lista<string> dictionary;
    ifstream file;
    file.open("english3.txt");
    std::string word;
    while(file>>word)
    {
        dictionary.Poner(word);
    }
    comparar(dictionary,Tabla);
    
    
    
    return 1;
};
