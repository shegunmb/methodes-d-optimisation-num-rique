#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int convertToString(string s){// attention convertit un string en int
    int result(0.);
    istringstream convert (s);
    if(!(convert >> result)) result = 0;
    return result;

}
double convertToStringd(string s){// attention convertit un string en int
    double result(0.);
    istringstream convert (s);
    if(!(convert >> result)) result = 0;
    return result;

}
string convertToInt(int s){// attention convertit un int en string
   string result;
    ostringstream convert;
    convert << s;
    result =convert.str();

    return result;

}
string convertToDouble(double s){// attention convertit un int en string
   string result;
    ostringstream convert;
    convert << s;
    result =convert.str();

    return result;

}

void split(const string &s, char delim, vector<string> &elems){//split une chaine de caractere

    stringstream ss;

    ss.str(s);
    string item;

    while(getline(ss,item,delim)){
        elems.push_back(item);
    }
}

vector<string> split(const string &s, char delim){ //split renvoyant un tableau

    vector<string>elems;
    split(s, delim, elems);
    return elems;
}

vector<double> convToIntArray(vector<string> arr){// transform un array de string en int

    vector<double> ari;
    int i(0),j;
    for(i=0; i< arr.size(); i++){
            j=convertToStringd(arr[i]);
        ari.push_back(j);
    }
    return ari;
}
vector<vector<int> > nbrSlacks(vector<vector<int> > mat, int var){//renvoie un tableau avec la position des lignes des slacks
    int i(0);
    vector<vector<int> > arr;
    vector<int> nbe;
    vector<int> nbf;

    for(i=0; i<mat.size(); i++){
                    if(mat[i][var]==2){nbe.push_back(i);}
                    else if(mat[i][var]==1){nbf.push_back(i);}

            }

arr.push_back(nbe);
arr.push_back(nbf);
return arr;
}
vector<int>  nbrSlacks2(vector<vector<string> > mat, int var){//renvoie un tableau avec la position des lignes des slacks
    int i(0);
    vector<int> nbe;



    for(i=0; i<mat.size(); i++){
                    if(mat[i][var]==">"){nbe.push_back(-1);}
                    else if(mat[i][var]=="<"){nbe.push_back(1);}
                    else if(mat[i][var]=="="){nbe.push_back(0);}

            }

return nbe;
}

vector<vector<string> > linForm(vector<vector<string> > mat, int var){
    int i(0),k;
    int l(0);
    string j;

    for(i=0; i<mat.size(); i++){//tout les membres de B sont positifs
       if(convertToString(mat[i][var+1])<0){
            for(k=0;k<var;k++){
                l=-convertToString(mat[i][k]);
                mat[i][k]= convertToInt(l);
            }
            l= -convertToString(mat[i][var+1]);
            mat[i][var+1]= convertToInt(l);

            if(convertToString(mat[i][var])==1){mat[i][var]="2";}
            else if(convertToString(mat[i][var])==2){mat[i][var]="1";}
        }
    }


    for(i=0; i<mat.size(); i++){
            if(mat[i][var] == "0"){ mat[i][var]="=";
               }
                else if(mat[i][var]=="1"){mat[i][var]="<";

                }
                else if(mat[i][var]=="2"){mat[i][var]=">";

                }
            }
        for(k=0; k< mat.size(); k++){

        for(i=0; i< mat[k].size(); i++){

                if(convertToString(mat[k][i])>=0&& i!= var){mat[k][i]="+"+mat[k][i];}

        }
    }
    for(i=0; i < var; i++){
             cout<<"X"<<i<<"    ";
}
cout<<endl;

for(i=0; i< mat[0].size(); i++){
            cout<< "-----";

        }
        cout<<endl;

for(k=0; k< mat.size(); k++){

        for(i=0; i< mat[k].size(); i++){
            cout<< mat[k][i]<<"    ";
        }
    cout<<endl;
}

return mat;
}
vector<vector<string> >stdForm(vector<vector<string> > &mat, vector<int> &slacks, int var){
        int nbslacks = slacks.size();
        int i(0);
        int j(0);
        int k,l;
        string tmp;



        vector<string> save;


    for(i=0; i<mat.size(); i++){
            for(j=(var+1); j<mat[i].size(); j++ ){
                 l=convertToString(mat[i][j]);
                 save.push_back(mat[i][j]);
            }
    }

    for(i=0; i<mat.size();i++){
        mat[i].pop_back();
        mat[i].pop_back();
    }

        for(i=0; i<mat.size(); i++){

            for(j= var, k=0; j<(var+nbslacks), k<slacks.size(); j++,k++){

                    if(slacks[k] == 1 && k==i){mat[i].push_back("+1"); }
                    else if(slacks[k] == -1 && k==i){mat[i].push_back("-1");}
                    else{mat[i].push_back("+0");}
            }
             for(j= var, k=0; j<(var+nbslacks), k<slacks.size(); j++,k++){

                    if(slacks[k] == -1 && k==i){mat[i].push_back("+1");}
                    else if(slacks[k] == -1 && k!=i){mat[i].push_back("+0");}
            }

        }
        for(i=0; i<mat.size(); i++){
            mat[i].push_back(save[i]);
        }
        cout<<endl;
 for(j=0; j< mat[0].size(); j++){
            if(j<(var)){cout<<"X"<<j<<"     ";}
            else if( j< (var+nbslacks) && j>= var){
                    if(slacks[j-var]== -1){cout<<"F"<<(j-var)<<"     ";}
                    else {cout<<"E"<<(j-var)<<"     ";}

            }
            else if( j<mat[0].size()-1 && j>= var+nbslacks){
                cout<<"A"<<(j-(var+nbslacks))<<"     ";
            }
            else{cout<<"B";}
}
cout<<endl;

for(i=0; i< mat[0].size(); i++){
            cout<< "------";

        }
        cout<<endl;
for(i=0;i< mat.size();i++){
    for(j=0;j<mat[i].size();j++){
        cout<<mat[i][j]<<"     ";
    }
    cout<<endl;
}

//cout<<endl;


        return mat;
}


vector<vector<string> > baseForm2s(vector<vector<string> >mat, vector<int> slacks, int var)
{
     int nbslacks = slacks.size();
        int i(0);
        int j(0);
        int k,l;
        string tmp;



        vector<string> save;


    for(i=0; i<mat.size(); i++){
            for(j=(var+1); j<mat[i].size(); j++ ){
                 l=convertToString(mat[i][j]);
                 save.push_back(mat[i][j]);
            }
    }

    for(i=0; i<mat.size();i++){
        mat[i].pop_back();
        mat[i].pop_back();
    }

        for(i=0; i<mat.size(); i++){

            for(j= var, k=0; j<(var+nbslacks), k<slacks.size(); j++,k++){

                    if(slacks[k] == 1 && k==i){mat[i].push_back("+1"); }
                    else if(slacks[k] == -1 && k==i){mat[i].push_back("-1");}
                    else{mat[i].push_back("+0");}
            }
             for(j= var, k=0; j<(var+nbslacks), k<slacks.size(); j++,k++){

                    if(slacks[k] == -1 && k==i){mat[i].push_back("+1");}
                    else if(slacks[k] == -1 && k!=i){mat[i].push_back("+0");}
            }

        }
        for(i=0; i<mat.size(); i++){
            mat[i].push_back(save[i]);
        }
        cout<<endl;
 for(j=0; j< mat[0].size(); j++){
            if(j<(var)){cout<<"X"<<j<<"     ";}
            else if( j< (var+nbslacks) && j>= var){
                    if(slacks[j-var]== -1){cout<<"F"<<(j-var)<<"     ";}
                    else {cout<<"E"<<(j-var)<<"     ";}

            }
            else if( j<mat[0].size()-1 && j>= var+nbslacks){
                cout<<"A"<<(j-(var+nbslacks))<<"     ";
            }
            else{cout<<"B";}
}
cout<<endl;

for(i=0; i< mat[0].size(); i++){
            cout<< "------";

        }
        cout<<endl;
for(i=0;i< mat.size();i++){
    for(j=0;j<mat[i].size();j++){
        cout<<mat[i][j]<<"     ";
    }
    cout<<endl;
}

//cout<<endl;


        return mat;
}

//==============================================


vector<string> zlinForm(vector<string> &mat, int slacks){
    int i(0);
    int j(mat.size());
    for(i=j; i<(j+slacks);i++){
        mat.push_back("0");
    }
    for(i=0; i< mat.size(); i++){
                if(convertToString(mat[i])>=0 && mat[i][0]!='+'){mat[i]="+"+mat[i];}
        }

    for(i=0;i< mat.size();i++){cout<<mat[i]<<"     ";}
     cout<<"Z"<<endl;

        return mat;
}
vector<string> zlinForm2(vector<string> &mat, vector<int> slacks){
    int i(0),cpt(0);
    int j(mat.size());
    int k(slacks.size());
    for(i=0;i<k;i++){
        cout<<"slacks i : "<<slacks[i]<<endl;
        if(slacks[i]=-1){

                cpt++;}
    }
    for(i=j; i<(j+k+cpt);i++){
        mat.push_back("0");
    }
    for(i=0; i< mat.size(); i++){
                if(convertToString(mat[i])>=0 && mat[i][0]!='+'){mat[i]="+"+mat[i];}
        }

    for(i=0;i< mat.size();i++){cout<<mat[i]<<"     ";}
     cout<<"Z"<<endl;

        return mat;
}

int stillpos(vector<string> &mat){
int p=0;
int i(0);
for(i=0;i< mat.size(); i++){
            if(convertToStringd(mat[i])>0){p++;}
        }

        return p;
}
vector<int> max_vector(vector<string> &mat){
    int i(0);
    double j(convertToStringd(mat[0]));
    vector<int> maxx;
    maxx.push_back(i);
    maxx.push_back(j);
    for(i=0; i<mat.size();i++){
        if(j< convertToStringd(mat[i])){
                j=convertToStringd(mat[i]);
                maxx[0]=i;
                maxx[1]=j;
        }
    }
    return maxx;
}

vector<double> max_vector(vector<double> &mat){
    double i(0);
    double j(mat[0]);
    vector<double> maxx;
    maxx.push_back(i);
    maxx.push_back(j);
    for(i=0; i<mat.size();i++){
        if(j< mat[i]){
                j=mat[i];
                maxx[0]=i;
                maxx[1]=j;
        }
    }
    return maxx;
}

vector<double> min_vector(vector<double> &mat){
    int i(0);
    double j(mat[0]);
    vector<double> maxx;
    maxx.push_back(i);
    maxx.push_back(j);
    for(i=0; i<mat.size();i++){
        if(j> mat[i]){
                j=mat[i];
                maxx[0]=i;
                maxx[1]=j;
        }
    }
    return maxx;
}
vector <vector<string> > doSimplex(vector<string> &matZ, vector<vector<string> > &mat, int var){

    int p(stillpos(matZ));
    int i(0);
    int j(0);
    int z(0);
    int zi(0);
    int k(0);
    int cpt(0);
    int a(mat[0].size()-1);
    int b(matZ.size());
    string stmp;


    while(p>0){

    double tmp(0.),tmp2(0.);
    vector <int> max_z;
    vector <int> ind_BA;
    vector <vector<double> >mat_BA_i;//retourne les Z/A et leurs indice


         max_z=  max_vector(matZ);//le z max
         cout<<endl<<"L'indice de la plus grande valeur de z est : "<<max_z[0]<<" et sa valeur est : "<<max_z[1]<<endl;
         vector <int> ind_A;
      for(i=0;i<mat.size();i++){//entier de la matrice A de la colonne du zmax

       ind_A.push_back(convertToStringd(mat[i][max_z[0]]));
      }
      //trouver le min B/A
      vector <double> mat_BA;//retourne les Z/A et leurs indice
      for(i=0;i<mat.size();i++){
        if(ind_A[i]>0 ){
            ind_BA.push_back(i);
            mat_BA.push_back(convertToStringd(mat[i][a])/ind_A[i]);
        }

      }
       for(i=0; i<ind_BA.size();i++){
        if(mat_BA[i]==min_vector(mat_BA)[1]){
                zi=ind_BA[i];
                cout<<endl<<"valeur de B/A la plus contraignante: "<<mat_BA[i]<<endl;
        }
       }//on a le min et son indice de la matrice b

        for(i=0;i<mat.size();i++){
                string stmp;
    double tmp(0.),tmp2(0.);

                if(i != zi && convertToStringd(mat[i][max_z[0]])!=0){
                    tmp=convertToStringd(mat[i][max_z[0]+var])-convertToStringd(mat[i][max_z[0]])*(1./convertToStringd(mat[zi][max_z[0]]));
                   mat[i][max_z[0]+var]=convertToDouble(tmp);

                    tmp=convertToStringd(mat[i][a])-convertToStringd(mat[i][max_z[0]])*(1./convertToStringd(mat[zi][max_z[0]]))*convertToStringd(mat[zi][a]);
                    mat[i][a]=convertToDouble(tmp);

                    mat[i][max_z[0]]="+0";
                }
        }
        for(i=0;i<b;i++){
                string stmp;
        double tmp(0.), tmp2(0.);
           if(i== convertToString(convertToInt(max_z[0]))){

                  tmp=convertToStringd(matZ[i+var])-convertToStringd(matZ[i])*(1./convertToStringd(mat[zi][max_z[0]]));
                    matZ[i]=""+convertToDouble(tmp);

                    matZ[i+var]= convertToDouble(tmp);

                    tmp=convertToStringd(matZ[b-1])-convertToStringd(matZ[i])*(1./convertToStringd(mat[zi][max_z[0]]))*convertToStringd(mat[zi][a]);

                    stmp =convertToDouble(tmp);

                    stmp=""+convertToDouble(tmp);

                    matZ.push_back("-"+stmp);

                    matZ[i]="+0";
            }
      }

cout<<endl;
cout<<endl;
cout<<"Base "<<cpt<<" : "<<endl;
 for(j=0; j< mat[0].size(); j++){
            if(j<var){cout<<"X"<<j<<"     ";}
            else if(j>= var && j< (mat[0].size()-1)){cout<<"E"<<(j-var)<<"     ";}
            else{cout<<"B";}
}
cout<<endl;

        cout<<endl;

for(i=0; i< mat[0].size(); i++){
            cout<< "-------";

        }
        cout<<endl;
for(i=0;i< mat.size();i++){
    for(j=0;j<mat[i].size();j++){
        cout<<mat[i][j]<<"     ";
    }
    cout<<endl;
}

cout<<endl;

for(i=0;i< matZ.size();i++){
    cout<<matZ[i]<<"     ";
}
cout<<"Z"<<endl;


p=stillpos(matZ);
cpt++;

        //=================================================================================
    }

    for(j=0; j< mat.size(); j++){
        for(i=0; i< mat[j].size(); i++){
                if(convertToString(mat[j][i])>=0 &&mat[j][i][0]!='+'){mat[j][i]="+"+mat[j][i];}
                }
            }
    mat.push_back(matZ);
    return mat;
}













vector<string> recupFile(string const &file){

    ifstream monFlux(file.c_str());

    string line;
    vector<string>lines;

      if(monFlux){

        while(getline(monFlux, line)){
                cout<<line<<endl;
            lines.push_back(line);
        }
    }
    else{
        cout<< "Error: file doesn't found."<<endl;
    }
    return lines;
}

void SolveSimplex(string const &file)
{
    int i(0),j;
    vector<string> lines ;
    cout<<"Contenu du fichier recuperer"<<endl;
    lines = recupFile(file);

    int variables= convertToString(lines[0]);
    int contraintes = convertToString(lines[1]);

    cout<<endl<<"Pour ce systeme le nombre de variables est : "<<variables<<endl;
    cout<<"Et son nombre de contraintes est : "<<contraintes<<endl<<endl;

    vector<vector<string> > matA;//contient les matrices Aet B sous forme de string
    vector<string> matZ= split(lines[lines.size()-1],' ');//la solution a optimiser


    for(j=2; j < (2+contraintes); j++){matA.push_back(split(lines[j], ' '));}//on ajoute les lignes

    cout<<endl<<"La forme initiale du systeme est : "<<endl<<endl;
    vector<vector<string> >matA2 = linForm(matA, variables);// forme lineaire
    vector<int>  matSlacks2 = nbrSlacks2(matA2,variables);
    cout<<endl<<"La forme standarde du systeme est : "<<endl<<endl;
    vector<vector<string> >matA3 = stdForm(matA2, matSlacks2, variables);// forme standarde
    vector<string> matZ2= zlinForm(matZ,matSlacks2.size() );// forme lineaire on peut l'ajouter
    cout<<endl<<"Resolution par la methode du simplex : "<<endl<<endl;
    vector<vector<string> >matA4 = doSimplex(matZ2,matA3, variables);

}

vector<vector<string> > do2PhaseSimplex(vector<string> &matZ, vector<vector<string> > &mat, int var, vector<vector<string> > mat0)
{
    int i(0), j(0),art(0),cpt(0);
    vector<string> matU;

    for(i=0; i<mat[0].size()-1; i++){
            int cpt(0);
        for(j=0; j< mat.size();j++){
            if(mat[j][i]== "-1" &&i> (var-1)){
                cpt++;
                art++;
            }
        }
        if(cpt> 0){
                matU.push_back("-1");
            }else{matU.push_back("+0");}
    }
    for(i=0; i<matU.size()-art; i++){

            if(matU[i]=="-1"){
                    cpt++;
                matU[matU.size()-cpt]="-1";
                matU[i]="+0";

            }
    }
    for(i=0; i< matU.size(); i++){
        cout<<matU[i]<<"     ";
    }
    cout<<"U"<<endl;

    // U en fonction des variables de la non base variable
    vector<int> indiceU;
    for(i=0; i< matU.size();i++){
        if(matU[i] == "-1"){

                for(j=0;j<mat.size();j++){
                    if(mat[j][i]=="+1"){
                       indiceU.push_back(j);
                    }
                }
        }
    }
    for(i=0; i<indiceU.size();i++){
            int tmp(0);
         for(j=0; j< matU.size(); j++){
           tmp=convertToString(matU[j])+convertToString(mat[indiceU[i]][j]);
            matU[j]=convertToInt(tmp);
         }

        }

        vector<int> ns =nbrSlacks2(mat0,var);
        for(i=0;i<ns.size(); i++){cout<<"slacks i : "<<ns[i];}
        matZ= zlinForm2(matZ,ns);
       // vector<vector<string> >base =stdForm(mat, ns, var);
        cout<<endl;
        cout<<endl;
        cout<<endl;
        for(i=0; i< mat.size(); i++){

            for(j=0; j< mat[0].size(); j++){
                cout<<mat[i][j]<<"     ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
        for(i=0; i< matU.size(); i++){
        if(convertToString(matU[i])>=0 && matU[i][0] !='+'){
            matU[i]="+"+matU[i];
        }
    }
         for(i=0; i< matZ.size(); i++){
        cout<<matZ[i]<<"     ";
    }
    cout<<"Z"<<endl;
    for(i=0; i< matU.size(); i++){
        cout<<matU[i]<<"     ";
    }
    cout<<"U"<<endl;
    mat.push_back(matZ);
   // vector <vector<string> > dS = doSimplex(matU,mat, var);
   //matZ =dS[dS.size()-1];
   //dS.pop_back();
   //vector<vector<string> > dS2 = doSimplex(matZ,mat,var);
    return mat;


}

//=============================================================================
//=============================================================================
//=============================================================================
//=============================================================================
//=============================================================================
//=============================================================================
//=============================================================================
//=============================================================================









int main()
{
    /*
   string const filename("files/LP_2.txt");
    ifstream monFlux(filename.c_str());


    string line;
    vector<string>lines;


//---------lecture du fichier et stockage des données
    if(monFlux){

        while(getline(monFlux, line)){
            lines.push_back(line);
        }
    }
    else{
        cout<< "Error: file doesn't found."<<endl;
    }

//-----------------------
int i(0);
int variables= convertToString(lines[0]);
int contraintes = convertToString(lines[1]);
vector<vector<string> > matA;//contient les matrices Aet B sous forme de string
vector<vector<double> > matAi;//sous forme d'entiers
vector<string> matZ;//la solution a optimiser
matZ= split(lines[lines.size()-1],' ');

//---------------simplex -----------
//1: trouver le nombre de slacks
//2: trouver le signe
// pour les lignes allant de 2 a nbrContraintes checker la valeur de elem(nbreVar) if 1 add sclack e sub slack f
int j(2);
int k(0);
vector<string> exple;
vector<double> explei;


for(j=2; j < (2+contraintes); j++){
        exple = split(lines[j], ' ');
        explei= convToIntArray(exple);
        cout<<lines[j]<<endl;
    matA.push_back(exple);
    matAi.push_back(explei);


}
cout<<endl;
cout<<endl;
for(j=0;j<matAi.size();j++){
    for(i=0; i< matAi[j].size();i++){
    cout<<matAi[j][i]<<"    ";
    }
    cout<<endl;
}

vector<vector<string> >matA2 = linForm(matA, variables);

for(j=0; j< variables; j++){
             cout<<"X"<<j<<"    ";
}
cout<<endl;

for(i=0; i< matA2[0].size(); i++){
            cout<< "-----";

        }
        cout<<endl;

for(k=0; k< matAi.size(); k++){

        for(i=0; i< matAi[k].size(); i++){
            cout<< matA2[k][i]<<"    ";
        }
    cout<<endl;
}

//vector<vector<double> > matSlacks = nbrSlacks(matAi,variables);
vector<int>  matSlacks2 = nbrSlacks2(matA2,variables);
vector<vector<string> >matA3 = stdForm(matA2, matSlacks2, variables);
 cout<<endl;
 cout<<endl;
for(i=0;i<matSlacks2.size(); i++){
    cout<<matSlacks2[i]<<"  ";
}
 cout<<endl;
 cout<<endl;
 for(j=0; j< matA3[0].size(); j++){
            if(j<variables){cout<<"X"<<j<<"     ";}
            else if(j>= variables && j< (matA3[0].size()-1)){cout<<"E"<<(j-variables)<<"     ";}
            else{cout<<"B";}
}
cout<<endl;

for(i=0; i< matA3[0].size(); i++){
            cout<< "------";

        }
        cout<<endl;
for(i=0;i< matA3.size();i++){
    for(j=0;j<matA3[i].size();j++){
        cout<<matA3[i][j]<<"     ";
    }
    cout<<endl;
}

cout<<endl;

vector<string> matZ2= zlinForm(matZ,matSlacks2.size() );
for(i=0;i< matZ2.size();i++){
    cout<<matZ2[i]<<"     ";
}
cout<<"Z"<<endl;

vector<double> m;
for(i=0;i<10; i++){m.push_back(i*10);};
 //cout<<max_vector(matZ2)[1]<<"minfeisjfeiofnq";

vector<vector<string> >matA4;
matA4 = do2PhaseSimplex(matZ2,matA3, variables, matA2);


*/
//cout<<"Hello World !!"<<endl;

SolveSimplex("files/LP_2.txt");
    return 0;
}
