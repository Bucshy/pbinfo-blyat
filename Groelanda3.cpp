#include <iostream>
using namespace std;
int citir(int v[], int n)
{if (n!=0){
citire(v,n-1);
cin>>v[n];
}
}
int afisar(int v[],int n)
{if (n!=0){
afisare(v,n-1);
cout<<v[n]<<" ";
}
}
int main()
{
    int n,v[21];
    cin>>n;
    citire(v,n);
    afisare(v,n);
    return 0;
}

void citire(int v[],int n)
{
    if (n!=0){
    citire(v,n-1);
    cin>>v[n];
}
}
void afisare(int v[],int n)
{if (n!=0){
afisare(v,n-1);
cout<<v[n]<<" ";
}
}
int numarare1(int v[],int st,int dr)
{   
    if(st==dr)
    return v[st];
    else{
        int mij=(st+dr)/2;
       if (numarare1(v,st,mij)==numarare1(v,mij+1,dr))
       return 1;
    }
}
int gh=1,gj=2;
int numarare(int v[],int n)
{
    if(numarare1(v,n,gj)==numarare1(v,n-1,gh))
    return 1+numarare(v,n);

}
int suma1(int v[],int st,int dr)
{   if(st==dr) return v[st];
    else 
    {
        int mij=(st+dr)/2;
        return suma1(v,st,mij)+suma1(v,mij+1,dr);
    }

}
int suma(int v[],int n, int i, int j)
{ 
    return(suma1(v,1,i-1)+suma1(v,j+1,n));
}
void num(int v[],int n)
{
    if (n!=0){
    num(v,n-1);
    cin>>v[n];
    if(v[n]<v[1])
    v[n]=0;
    cout<<v[n]<<" ";
}
}
int oglindit(int n)
{
    int p=0;
    if(n)
    p=p+n%10;
    return p+(oglindit(n/10)*10);
}
void muta(int v[],int n)
{
    v[n]=v[n+1];
    muta(v,n+1);
}
int elimina(int v[],int n)
{   
    if(v[n]==oglindit(v[n]))
    muta(v,n);

}
void afisare1(int v[],int n)
{if (n!=0){
afisare(v,n-1);
if(oglindit(v[n]))
muta(v,n);
cout<<v[n]<<" ";
}
}
int main()
{
    cout<<"Bun venit in meniu"<<endl;
    cout<<"Pentru a alege o cerinta, alege un numar de la 1 la 4,inclusiv, pentru a selecta o cerinta"<<endl;
    cout<<"1-cerinta 1 numarare"<<endl<<"2=cerinta 2 suma"<<endl<<"3-cerinta 3 num"<<endl<<"4-cerinta 4 elimina"<<endl;
    cout<<"Introduce cerinta!"<<endl;
    int i,v[10001],n,m,q;
    cin>>i;
    if(i==1)
    {   cout<<"introdu cifra"<<endl;
        cin>>n;
        cout<<"introdu elementele sirului"<<endl;
        citire(v,n);
        cout<<"rezultatul este"<<" "<<numarare(v,n);
    }
    if(i==2){
        cout<<"introdu cifra"<<endl;
        cin>>n;
        cout<<"introdu elementele sirului"<<endl;
        citire(v,n);
        cout<<"introdu intervalul interzis"<<endl;
        cin>>m>>q;
        cout<<"rezultatul este"<<" "<<suma(v,n,m,q);
    }
    if(i==3)
    {   
        cout<<"introdu cifra"<<endl;
        cin>>n;
        cout<<"introdu elementele sirului"<<endl;
        num(v,n);
    }
    if(i==4)
    { 
        cout<<"introdu cifra"<<endl;
        cin>>n;
        cout<<"introdu elementele sirului"<<endl;
        citire(v,n);
        elimina(v,n);
        cout<<"sirul fara palindrom este"<<" ";
        afisare1(v,n);
    }
    return 0;
}
int CautareBinara(int Left, int Right, int x)
{   int V[122];
    if(Left > Right)
        return -1;
    else
    {
        int Mid =(Left+Right)/2;
        if(x == V[Mid])
            return Mid;
        if(x < V[Mid])
            return CautareBinara(Left, Mid-1, x);
        else
            return CautareBinara(Mid+1, Right, x);
    }
}
