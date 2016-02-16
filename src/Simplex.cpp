//============================================================================
// Name        : Simplex.cpp
// Author      : Rafael
// Version     :
// Copyright   : GNU
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <regex>
#include <algorithm>
#include <iterator>
#include <cmath> 


using namespace std;



int coluna = 0;
int linha = 0;


bool construirTabela();
bool Simplex(double **_tableus);
bool verificarSolucaoOtima(double **_tableus);
bool is_digits(const std::string &str);


double maxzValores[100];
string maxzVariaveis[100];

int variaveisPrincipais = 0;
int subs = 0;
int cont=0;
// int coluna = 0;
// int linha = 0;



bool construirTabela(){
	 coluna = variaveisPrincipais + subs + 2;
	 linha = subs + 1;

	 // array<double,coluna,linha> tableus
	 // double tableus[linha][coluna];


	double **tableus=new double*[linha];
			for (int i=0;i<linha;i++)
	{
	  tableus[i]=new double[coluna];
	}
	 

	int i,j;

	// struct tabela tableus[linha][coluna];
	



	for (int n=0; n<linha; n++){
    for (int m=0; m<coluna; m++)
    {
      tableus[n][m] = 0.000;
    }
    
    }

/*
maxzValores[j]
de 1 ate variaveisPrincipais + 1
sao as minhas variaveis!!!!!!!!!!!!!!!!!!!!!!!!!!! 
 */

//preenchendo a primeira linha Z
int aux=0;
		for (int j = 0; j < coluna; ++j)
		{
			//um if para cada variavel encontrada previamente
			if(maxzVariaveis[j].compare("sol")){
				// cout << "entre: " << maxzVariaveis[j] ;

			tableus[0][j] = maxzValores[aux];
			aux++;
			}
			else{
				// cout << "sollllllllllll: " << maxzVariaveis[j];
				for (int z = j; z < coluna; z++)
				{
					if( z   == coluna -1 ){
						
						tableus[0][z] = maxzValores[aux];
						aux++;
					}else{
						
						tableus[0][z] = 0.000;
					}
				}
				j= coluna;


		}
	}

//preenchendo as demais linhas
	for (int i = 1; i < linha; ++i)
	{
		/* code */
	

		for (int j = 0; j < coluna; ++j)
		{
			tableus[i][0] = 0.000;
			for (int var = 1; var < variaveisPrincipais+1; ++var)
			{
				/* code */
				if(!maxzVariaveis[aux].compare(maxzVariaveis[var])){
					// achei x1 e x1
					// cout << maxzVariaveis[var] << endl;
					// cout << maxzVariaveis[aux] << endl;
					tableus[i][var] = maxzValores[aux];
					aux ++;
				}
			}

			if(!maxzVariaveis[j].compare("sol")){
				
				for (int z = j; z < coluna; z++)
				{
					if( z   == coluna -1 ){
						
						tableus[i][z] = maxzValores[aux];
						aux++;
					}else{
						
						
							tableus[i][z] = 0.000;
						}
						
					}
					tableus[i][j-1+i] = 1.000;
				
				j= coluna;


		}


		}

		}


		
		
	for (int i = 1; i <= variaveisPrincipais; ++i)
	{
		/* code */
		tableus[0][i] *= -1;
	}


	for (int i = 0; i <= variaveisPrincipais; ++i)
	{
		cout << maxzVariaveis[i] << "\t";
	}
	cout << endl;


	for (int n=0; n<linha; n++){
    for (int m=0; m<coluna; m++)
    {
      cout << tableus[n][m] << "\t";
    }
    cout << endl;
    }

    if(Simplex(tableus)){
    	cout << "ate mais";

    }



	return true;
}

bool Simplex(double **_tableus){


string baseVariaveis[variaveisPrincipais + 1];
baseVariaveis[0] = "z";

double resultados[variaveisPrincipais + 1];
resultados[0] = 0;

//inicializando meu baseVariaveis
for (int i = 1; i < variaveisPrincipais + 1; ++i)
{
	/* code */
	baseVariaveis[i] = "?";
	resultados[i] = 0;
}




while(!verificarSolucaoOtima(_tableus)) {

    // achando o maior coeficiente da linha z
    double maior = abs(_tableus[0][1]);
    int posicao = 1;
    for (int j = 2; j <= variaveisPrincipais; ++j)
    {
    	// cout << maior << endl;
    	if(maior < abs(_tableus[0][j])){
    		posicao = j;
    		maior = abs(_tableus[0][j]);	
    	}
    	/* code */
    }

    // cout << "Posicao " << posicao<< "\t" << "Valor: "<< maior <<endl;
    
    double maiorRazoes[linha];
    maiorRazoes[0] = -1;
    
    for (int i = 1; i < linha; ++i)
    {
    	if(!_tableus[i][posicao] == 0){
   
    		maiorRazoes[i] = _tableus[i][coluna-1] / _tableus[i][posicao];
    		
    		
    }else{
    	maiorRazoes[i] = -1;
    }
   

    }




    int posicaoDois;
    double tempMenor = 10000000;
    
    for (int i = 0; i < linha; ++i)
    {

    	if(maiorRazoes[i] >= 0){
    	
    	if(  tempMenor > maiorRazoes[i]){
    		
    		tempMenor = maiorRazoes[i];
    		posicaoDois = i;
    	}
    	}
    	
    	/* code */
    }

    // cout << "PosicaoDois " << posicaoDois<< "\t" << "valor: " << tempMenor << endl;
    
    // cout << _tableus[posicaoDois][posicao] << endl;








	double divisor = _tableus[posicaoDois][posicao];
	double linhaPivo[coluna];
	     for (int z = 0; z < coluna; ++z)
    {
    	
    	
    	_tableus[posicaoDois][z] = _tableus[posicaoDois][z] / divisor; 
    	linhaPivo[z] = _tableus[posicaoDois][z];
    	
    	
    }

cout << "Aqui depois de fazer a parte Linha do pivo atual / elemento pivo \n";



  	  for (int n=0; n<linha; n++){
    for (int m=0; m<coluna; m++)
    {
      cout << _tableus[n][m] << "\t";
    }
    cout << endl;
    }


  
  for (int i = 0; i < linha; ++i)
  {
  	

  	double divisorPivo = _tableus[i][posicao];

  	for (int j = 0; j < coluna; ++j)
  	{
  	
  		_tableus[i][j] = _tableus[i][j] - (divisorPivo * linhaPivo[j]) ;

  	}

  	if((i+1) == posicaoDois)
  		i++;

	
  }

  cout << "\n";

cout << "Aqui depois de fazer a parte Linha atual - Coef coluna pivo * nova linha pivo \n";
// baseVariaveis[posicaoDois] = maxzVariaveis[posicao];

// resultados[posicao] = _tableus[posicaoDois][coluna - 1];





  	  for (int n=0; n<linha; n++){
    for (int m=0; m<coluna; m++)
    {

      cout << _tableus[n][m] << "\t";
    }
    cout << endl;
    }



baseVariaveis[posicaoDois] = maxzVariaveis[posicao];
resultados[posicao] = _tableus[posicaoDois][coluna - 1];

for (int i = 1; i <= variaveisPrincipais; ++i)
{
	 
	 	for (int j = 1; j <= variaveisPrincipais; ++j)
	 	{
	 		
	 		if (!maxzVariaveis[i].compare(baseVariaveis[j]))
	 		{
	 			resultados[i] = _tableus[j][coluna - 1];
	 		}
	 		
	 		
	 	}


}



}

//copiando os resultados para serem mostrados
//
resultados[0] = _tableus[0][coluna - 1];
// for (int i = 0; i <= variaveisPrincipais; ++i)
// {
// 	cout << baseVariaveis[i] << " " << _tableus[i][coluna -1]<<endl;
// }

cout << endl;




cout << "RESULTADO" << endl;
for (int i = 0; i <= variaveisPrincipais; ++i)
{
	 if(maxzVariaveis[i].compare("?"))
	cout << maxzVariaveis[i] << " " << resultados[i] << endl;
}

return true;
}



bool verificarSolucaoOtima(double **_tableus){
	
	for (int i = 0; i < coluna; ++i)
	{
		/* code */
		if(_tableus[0][i] <0)
			return false;
	}

	return true;

}


bool regexParse(string str, bool restricao){
	regex equacao("\s*(\s*([+]|-)?\s*(([0-9]+[.]?[0-9]*)|([0-9]*[.]?[0-9]+)))\*([[:w:]]+)\s*");

	cout << str<<endl;
	string delimiterMenorIgual = "<=";
	string token;



if(restricao){
	size_t pos2 = 0;
			
	
			token = str;
			str = "";

			while ((pos2 = token.find(delimiterMenorIgual)) != string::npos) {
				
			   str = token.substr(0, pos2);
			   // cout <<"str: "<< str << endl;
			   

			   token.erase(0, pos2 + delimiterMenorIgual.length());
			   token.erase(token.length()-1, token.length());
			}
			// cout <<"Restritcao:str2: "<< str << endl;
			// cout <<"Restricaotoken: "<< token << endl;
}

	sregex_iterator pos(str.cbegin(), str.cend(),equacao);
	sregex_iterator end;

	auto words_end = sregex_iterator();
	int a = distance(pos, end);
	string::size_type sz;
	// cout << "Quantidade de termos encontrados pelo regex: " << a << endl;

	//aqui eu defino a quantidade de variaveis na primeira vez que char a funcao regexParse
	if(variaveisPrincipais == 0 && !restricao)
		//a /2 - porque a sao tudo que encontrou, todos os sub grupos. a/2 sao apenas a quantidade de variaveis
		variaveisPrincipais = a/2;


	
			


	

	size_t acheiMenorIgual = (str.find(delimiterMenorIgual));
	

	if( restricao ){
		subs++;
		// cout << "Entrei aqui, devo contar as restricoes para aumentar a quantidade de subs: "<< subs<<endl;

	}

		/* quando eh uma restricao a quantidade de elementos encontrados eh impar
		pois tem o valor apois o <= */


// locale loc;
	for (int var = 0; var < a; var++, ++pos) {
		int cal = (var) % 2 ;
		// cout << "Z: "<<"var: "<< var << " "<<pos->str(0).c_str() << endl;
			//cal != 0 &&
			

			if(!is_digits(pos->str(0)) ) {
		
	
				maxzVariaveis[cont] = pos->str(0);
				cont++;
			}else {
				
        maxzValores[cont] = stod(pos->str(0));
    										
				
		}
		// cout << "Z: "<<"var: "<< var << " "<<pos->str(0) << endl;		
}
		

	

	if (!restricao)
	{
		/* code */
		maxzVariaveis[cont] = "sol";
				
		maxzValores[cont] = 0;
		cont++;
	}else{
			maxzVariaveis[cont] = "sol";
				
				maxzValores[cont] = stod(token);
				cont++;

	}


	



	return true;


}

bool is_digits(const std::string &str) {
    return str.find_first_not_of("-0123456789.") == std::string::npos;
}


int main() {



	char my_character;
	char linha2[10];
	char linha[1000];
	string linhaZ, linhaSujet, linhaN;
	int number_of_lines = 0;

	// struct tabela;
	int num_linha = 0;

	/**
	 * Parte que abre o arquivo
	 *
	 */
	ifstream fin;
	fin.open("data.txt");



	if (!fin.is_open())
	{
		cout << "Nao abri o arquivo!";
		fin.close();
		return 0;
	}




	/**
	 * Pegando a linha Z e verificando se existe o ;
	 */
	getline(fin, linhaZ);
	// cout << "z: "<< linhaZ<< endl;
	size_t found = linhaZ.find(';');
	if (found!=string::npos && linhaZ.length() == found+1){
		//mandar linhaZ para analise
		// cout << "achei o Z " << linhaZ.length() << " " << found+1 << endl;
		maxzValores[cont] = 1 ;
maxzVariaveis[cont] = "z";
cont++;
		if(regexParse(linhaZ, false)){
			// cout<<"entrou no regexParse" << endl;
		}
	}
	else {
		cout << "Erro: faltou o ; ou foi colocado no lugar errado na linha 1! " << linhaZ.length() << " " << found+1 << endl;
		fin.close();
		return 0;
	}

	/**
	 * Sou chato! Tem que existir na segunda linha "subject to"
	 */
	getline(fin, linhaSujet);
	// cout << "Segunda: "<< linhaSujet<< endl;
	if (linhaSujet.compare("subject to") == 0){
		// cout << "achei " << linhaSujet.length() << " " << found << endl;
	}
	else {
		cout << "Erro: Segunda linha nao tem subject to!"<< endl;
		fin.close();
		return 0;
	}



	string limites = "bounds";
	bool restricao = true;
	while(!fin.eof())
	{
		getline(fin, linhaN);
		// cout << "Linha: "<< num_linha + 1<< ": " <<linhaN<< endl;

		if (!linhaN.compare(limites) == 0 && restricao){
			//mandar restricao para analise
			// cout << "restricao "<< num_linha + 1 <<endl;
			if(regexParse(linhaN,restricao )){
				// cout<<"entrou no regexParse" << endl;
			}
			num_linha++;
		}
		else {
			// cout << "Erro: achei end, o que devo fazer?"<< endl;
			// limites = "end";
			 restricao = false;

		}

	}
	// for (int i = 0; i < cont; ++i)
	// {
	// 	cout << "maxzVariaveis: "<< maxzVariaveis[i]<< " maxzValores: "<< maxzValores[i]<< endl;
	// 	cout <<  endl;
	// }
	if(construirTabela()){
		// cout << "deu certo";
	}
	
	
	fin.close();

	return 0;

}


//sregex_token_iterator pos(str.cbegin(), str.cend(),e, 1);
//sregex_token_iterator end;
//
//for (; pos!=end;pos++) {
//
//	cout << "encontrei: " << pos->str();
//
//	cout << endl;
//
//}

//cin >> str;





