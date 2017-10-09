#include <iostream>
#include <fstream>
#include <string>

#include <list>

#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Pessoa;
class ListaPessoa;

class InteresseAtividade;
class ListaInteressesAtividades;
//int criaRedeFile();


//Classe InteresseAtividade
class InteresseAtividade
{
private:
	string informacao;
	InteresseAtividade* proximo;
	
public:
	InteresseAtividade(string n) // construtor
	{
		this->informacao = n;
		this->proximo = NULL;
	}

	string getInteresseAtividade() // obtém o valor
	{	
		return informacao;	
	}

	InteresseAtividade* getProximoInteresseAtividade() // obtém a próxima Pessoa
	{
		return proximo;
	}

	void setProximoInteresseAtividade(InteresseAtividade* p) // seta a próxima Pessoa
	{
		proximo = p;
	}
};


//Lista de Interesse Atividades
class ListaInteressesAtividades
{
private:
	InteresseAtividade* cabeca; // primeiro elemento
	InteresseAtividade* cauda; // último elemento

public:
	ListaInteressesAtividades()
	{
		// se não passar elemento, então cabeca e cauda são NULL
		cabeca = NULL;
		cauda = NULL;
	}

	ListaInteressesAtividades(string n)
	{
		// se passar elemento, então cria novo No
		cabeca = new InteresseAtividade(n);
		cauda = cabeca;
	}

	virtual ~ListaInteressesAtividades() // destrutor
	{
		delete cabeca;
	}

	void mostrar() // mostra todos os elementos da ListaInteressesAtividades
	{
		cout << "\nImprimindo todos os elementos...\n";
		InteresseAtividade* c = cabeca;

		if(vazia())
			cout << "A ListaInteressesAtividades NAO possui elementos!!\n";
		else
		{
			while(c) // percorre a ListaInteressesAtividades
			{
				cout << c->getInteresseAtividade() << endl;
				c = c->getProximoInteresseAtividade();
			}
			cout << endl;
		}
	}

	bool vazia() // verifica se a ListaInteressesAtividades está vazia
	{
		return (cabeca == NULL);
	}

	

	// insere no final (semelhante a push_back da list)
	void inserir(string n)
	{
		InteresseAtividade* novo_InteresseAtividade = new InteresseAtividade(n);

		if(vazia())
		{
			cabeca = novo_InteresseAtividade;
			cauda = novo_InteresseAtividade;
		}
		else
		{
			cauda->setProximoInteresseAtividade(novo_InteresseAtividade);
			cauda = novo_InteresseAtividade;
		}
	}
	
	void addInteresseAtividade(InteresseAtividade *novoInteresseAtividade)
	{
		if(vazia())
		{
			cabeca = novoInteresseAtividade;
			cauda = novoInteresseAtividade;
		}
		else
		{
			cauda->setProximoInteresseAtividade(novoInteresseAtividade);
			cauda = novoInteresseAtividade;
		}
	}

	// retorna o tamanho da ListaInteressesAtividades
	int tamanho()
	{
		if(vazia()) // se for vazia, entã retorna 0
			return 0;

		InteresseAtividade* c = cabeca;
		int tam = 0;
		
		// percorre a ListaInteressesAtividades
		do
		{
			c = c->getProximoInteresseAtividade();
			tam++;
		}
		while(c);
		
		return tam;
	}

	// verifica se um elemento existe na ListaInteressesAtividades
	bool existe(string n)
	{
		InteresseAtividade* c = cabeca;
		
		while(c)
		{
			if(c->getInteresseAtividade() == n)
				return true;
			c = c->getProximoInteresseAtividade();
		}
		return false;
	}
	
	InteresseAtividade *retornaInteresseAtividade(string n)
	{
		InteresseAtividade* c = cabeca;
		
		while(c)
		{
			if(c->getInteresseAtividade() == n)
				return c;
			c = c->getProximoInteresseAtividade();
		}
		return NULL;
	}

	
};



//Classe Pessoa
class Pessoa
{
private:
	string nome;
	
	list<Pessoa*> contatos;
	list<InteresseAtividade*> interesseAtividades;
	
	Pessoa *proxima;
	
public:
	
	Pessoa(string n) // construtor
	{
		this->nome = n;
		this->proxima = NULL;
	}

	string getNome() // obtém o valor
	{
		return nome;
	}
	
	list<Pessoa*> getContatos()
	{
		return contatos;
	}
	
	
	void addContato(Pessoa *novaPessoa)
	{	
		contatos.push_back(novaPessoa);
	}
	
	void removerContato(string nome)
	{	
		cout << "Remover Contato" << endl;
		list<Pessoa*>::iterator iter; 
		 for(iter = contatos.begin();
		 iter!=contatos.end(); iter++)
		 {
			 Pessoa *v1 = *iter;
			 if (v1->getNome() == nome)
			 {
			 	cout << "é igual: " << v1->getNome() << endl;
	   	   	    iter=contatos.erase(iter);
			 }
		 } 
	}
	
	void removerInteresseAtividades(string nome)
	{	
		cout << "Remover Interesse Atividades" << endl;
		list<InteresseAtividade*>::iterator iter; 
		 for(iter = interesseAtividades.begin();
		 iter!=interesseAtividades.end(); iter++)
		 {
		 InteresseAtividade *v1 = *iter;
		 if (v1->getInteresseAtividade() == nome)
		 {
		 	cout << "é igual: " << v1->getInteresseAtividade() << endl;
   	   	    iter=interesseAtividades.erase(iter);
		 }
		 } 
	}
	
	void mostrarContatos() // mostra todos os elementos da ListaPessoa
	{	
		
		 list<Pessoa*>::iterator iter; 
		 for(iter = contatos.begin();
		 iter!=contatos.end(); iter++)
		 {
		 Pessoa *v1 = *iter;
		 cout << v1->getNome() << endl;
		 v1->mostrarInteressesAtividades();
		 }
	}
	
	
	void mostrarInteressesAtividades() // mostra todos os elementos da ListaPessoa
	{	
		list<InteresseAtividade*>::iterator iter; 
		
		for(iter = interesseAtividades.begin();
		iter!=interesseAtividades.end(); iter++)
		{
			InteresseAtividade *v1 = *iter;
			cout << "\t" << v1->getInteresseAtividade() << endl;
		} 
	}
	
	
	
	list<InteresseAtividade*> getInteressesAtividades()
	{
		return interesseAtividades;
	}
	
	///////
	void setInteresseAtividade(InteresseAtividade * novoInteresseAtividade)
	{
		interesseAtividades.push_back(novoInteresseAtividade);
	}
	
	void addInteresse(InteresseAtividade *novoInteresse)
	{	
		interesseAtividades.push_back(novoInteresse);
	}
	///////

	Pessoa* getProxima() // obtém a próxima Pessoa
	{
		return proxima;
	}

	void setProxima(Pessoa* p) // seta a próxima Pessoa
	{
		proxima = p;
	}
	
	bool existePessoa(string n)
	{
		list<Pessoa*>::iterator iter; 
		 for(iter = contatos.begin();
		 iter!=contatos.end(); iter++)
		 {
		 Pessoa *v1 = *iter;
		 if( v1->getNome() == n)
		 	return true;
		 }
		 return false;
	}
	
	bool existeInteresseAtividade(string n)
	{
		list<InteresseAtividade*>::iterator iter; 
		 for(iter = interesseAtividades.begin();
		 iter!=interesseAtividades.end(); iter++)
		 {
		 InteresseAtividade *v1 = *iter;
		 if( v1->getInteresseAtividade() == n)
		 	return true;
		 }
		 return false;
	}
	
};

//Lista de Pessoa
class ListaPessoa
{
private:
	Pessoa* cabeca; // primeiro elemento
	Pessoa* cauda; // último elemento

public:
	ListaPessoa()
	{
		// se não passar elemento, então cabeca e cauda são NULL
		cabeca = NULL;
		cauda = NULL;
	}

	ListaPessoa(string n)
	{
		// se passar elemento, então cria novo No
		cabeca = new Pessoa(n);
		cauda = cabeca;
	}

	virtual ~ListaPessoa() // destrutor
	{
		delete cabeca;
	}

	void mostrar() // mostra todos os elementos da ListaPessoa
	{
		//cout << "\nImprimindo todos os elementos...\n";
		Pessoa* c = cabeca;

		if(vazia())
			cout << "A ListaPessoa NAO possui elementos!!\n";
		else
		{
			while(c) // percorre a ListaPessoa
			{
				cout << c->getNome() << endl;
				c = c->getProxima();
			}
			cout << endl;
		}
	}



	bool vazia() // verifica se a ListaPessoa está vazia
	{
		return (cabeca == NULL);
	}

	

	// insere no final (semelhante a push_back da list)
	void inserir(string n)
	{
		Pessoa* nova_pessoa = new Pessoa(n);

		if(vazia())
		{
			cabeca = nova_pessoa;
			cauda = nova_pessoa;
		}
		else
		{
			cauda->setProxima(nova_pessoa);
			cauda = nova_pessoa;
		}
	}
	
	void addPessoa(Pessoa *novaPessoa)
	{
		if(vazia())
		{
			cabeca = novaPessoa;
			cauda = novaPessoa;
		}
		else
		{
			cauda->setProxima(novaPessoa);
			cauda = novaPessoa;
		}
	}
	
	

	// retorna o tamanho da ListaPessoa
	int tamanho()
	{
		if(vazia()) // se for vazia, entã retorna 0
			return 0;

		Pessoa* c = cabeca;
		int tam = 0;
		
		// percorre a ListaPessoa
		do
		{
			c = c->getProxima();
			tam++;
		}
		while(c);
		
		return tam;
	}

	// verifica se um elemento existe na ListaPessoa
	bool existe(string n)
	{
		Pessoa* c = cabeca;
		
		while(c)
		{
			if(c->getNome() == n)
				return true;
			c = c->getProxima();
		}
		return false;
	}
	
	Pessoa *retornaPessoa(string n)
	{
		Pessoa* c = cabeca;
		
		while(c)
		{
			if(c->getNome() == n)
				return c;
			c = c->getProxima();
		}
		return NULL;
	}
	
	Pessoa *retornaCabeca()
	{
		return cabeca;
	}
	
	Pessoa *retornaCauda()
	{
		return cauda;
	}

	
};

void processaContatos(char nomeArquivo[], ListaPessoa *cont)
{	
	std::ifstream file(nomeArquivo);
    std::string str; 
    while (std::getline(file, str))
    {
        cout << "|" << str << "|" << endl;
        cont->inserir(str);
    }
     
    
};

string substring(string const& str, string const& delim){
  return str.substr(str.find(delim) + delim.size());
};

//metodo auxiliar para dividir string
vector<string> split(const string& s, const string& delim, const bool keep_empty = true) {
    vector<string> result;
    if (delim.empty()) {
        result.push_back(s);
        return result;
    }
    string::const_iterator substart = s.begin(), subend;
    while (true) {
        subend = search(substart, s.end(), delim.begin(), delim.end());
        string temp(substart, subend);
        if (keep_empty || !temp.empty()) {
            result.push_back(temp);
        }
        if (subend == s.end()) {
            break;
        }
        substart = subend + delim.size();
    }
    return result;
}

int criaRedeFile(ListaPessoa &contato)
{
	Pessoa *cont = contato.retornaCabeca();
	
	InteresseAtividade * inter;
	list<Pessoa*> ctt;
	list<InteresseAtividade*> listInter;
	std::ofstream outfile ("redeNew.txt");
	while(cont)
	{		//UserNAme
			outfile << cont->getNome() << endl;
		
			//Interesses Atividades
			listInter = cont->getInteressesAtividades();
			
			list<InteresseAtividade*>::iterator iter; 
			for(iter = listInter.begin();
			iter!=listInter.end(); iter++)
			{
				InteresseAtividade *v1 = *iter;
				outfile << v1->getInteresseAtividade() << endl;
				
			}
			
			//Contatos
			ctt = cont->getContatos();
			list<Pessoa*>::iterator iterCtt; 
			for(iterCtt = ctt.begin();
			iterCtt!=ctt.end(); iterCtt++)
			{
				Pessoa *v1 = *iterCtt;
				outfile << "-- " << v1->getNome() << endl;
			}
		 
		
		cont = cont->getProxima();
		//new User
		outfile << "#" << endl;
	}
	outfile.close();
	
	
	return 0;
}

int criaGraphFile(ListaPessoa &contato)
{	
	//Seleciona lista de usuarios
	Pessoa *cont = contato.retornaCabeca();
	Pessoa *cont2 = cont->getProxima();
	
	//Auxiliares de manipulacao
	InteresseAtividade * inter;
	list<Pessoa*> ctt;
	string str;
	string str2;
	string op1;
	
	//Auxiliar com duplicacoes
	std::ofstream outfile ("graphAux.dot");
	
	//percorre os usuarios	    
	while(cont)
	{		
			//UserNAme
			str = cont->getNome();

			
			//pegar do usuario seus contatos
			ctt = cont->getContatos();
			
			list<Pessoa*>::iterator iterCtt; 
			for(iterCtt = ctt.begin();
			iterCtt!=ctt.end(); iterCtt++)
			{
				Pessoa *contato = *iterCtt;
				//pega do nome do contato
				str2 = contato->getNome();
				
				//cria string da rede de contato, no padrao graphviz
				op1 = '"' + str + '"' + " -- " +  '"' + str2 + '"';
				
				//salvar a string em 'graphAux.dot'
				outfile << op1 << endl;
			
			}
			
			//percorre os usuarios
			cont = cont->getProxima();
	}
	outfile.close();		
	return 0;
}


int removeDuplicacoes()
{	//remove as duplicacoes do arquivo auxiliar
	//percorrendo todas as linhas do auxiliar
	//e comparando com a inversao do relacionamento
	//novamente com todo o arquivo auxiliar
	//afim de nao pegar relacionamento duplicado
	//E manda pro arquivo 'rede.dot' somente as linhas
	//que nao encontra duplicidades
	
	ifstream file("graphAux.dot");
	string strAux; 
	
	//cria arquivo final 
	ofstream outfile ("rede.dot");
	
	//cabecalho do graphviz
	outfile << "graph" << endl;
	outfile << "{ overlap=false" << endl;
	
	string line;
	string strRemove;
	
	//existe correspondencia duplicada de contato
	bool isPresent = false;
	
	//percorrer o file auxiliar
	//cada linha dentro de strAux
	
	//Pega todos os relacionamentos: (tem duplicidades)
    while (std::getline(file, strAux))
    {	
		//dividir a linha do arquivo, para pegar o nome do
		//usuario e do contato e poder comparar se eles
		//possuem duplicacoes  
		  
		//Ex: strAux = 	("Chuck Norris" -- "Jackie Chan");
		//quebra String no ' -- '	
		const vector<string> words = split(strAux, " -- ");
		//words[0] = "Chuck Norris";
		//words[1] = "Jackie Chan";
		
		
		// abre arquivo com duplicacoes
		ifstream fileAux ("graphAux.dot");
		          
		//inicializa sem correspondencia de duplicacao
		isPresent = false;
		
		// a cada loop tem uma linha do arquivo 
		//line é cada linha do arquivo em string
		
		//Para cada linha do arquivo de duplicidades
		//verifico se existe alguma duplicidade
		while (getline(fileAux, line)) { 
			
			//String auxiliar que verifica se existe correspondencia
			//de duplicacao de relacionamento.
			//Exemplo:
			//"Chuck Norris" -- "Jackie Chan" = words[0] + ' -- ' + words[1];
			//igual a 
			//"Jackie Chan" -- "Chuck Norris" = words[1] + ' -- ' + words[0];
			strRemove = words[1] + " -- " + words[0];
			
			//Se eu tenho um relacionamento
			//Ex: "Chuck Norris" -- "Jackie Chan" no arquivo
			if (line == strAux)
			{	//sim, tenho um relacionamento
				isPresent = true;
			}
			
			//se eu tenho relacionamento
			//tenho que verificar as duplicidades
			//a duplicidade é 'strRemove'
			if(isPresent)
			{	
				//tenho uma duplicidade de relacionamento
				//preciso remover
				if (line == strRemove){
					//cout << "Mantem: " << strAux << endl;
		    		//cout << "Remove: " << str2 << endl;
		    		
		    		//meu arquivo final 'rede.dot'
		    		//recebe somente o relacionamento, nao a sua duplicidade
		    		//Adiciono "Chuck Norris" -- "Jackie Chan"
		    		//E nao adiciono "Jackie Chan" -- "Chuck Norris"
					outfile << strAux << endl;
					
					//relacionamento não existe mais, pq acabei de adicionar ele
					//no meu arquivo da 'rede.dot'
					isPresent = false;
				}
			}
			
	    }

		fileAux.close();
	}
	outfile << "}" << endl;
	outfile.close();
    		
	return 0;
}


int menu(ListaPessoa contatos, ListaInteressesAtividades interessesAtividades)
{	int opcao = 0;
	
	
	//cout << "Opcao Escolhida: " << opcao << endl;
	//Verifica Se tem user logado
	bool logado = false;
	
	//Auxiliares de Manipulacao
	Pessoa *pessoaAux;
    Pessoa *contatoAux;
    InteresseAtividade *interesseAtividadeAux;
    
    string strAux = "";
    string strAux2;
    
	while (opcao != 6)
	{
	   	cout << "\n\n---------------------" << endl;
		cout << "FACINBook" << endl;
		cout << "1 - Login" << endl;
		cout << "2 - Logout" << endl;
		cout << "3 - Contatos" << endl;
		cout << "4 - Interesses/Atividades" << endl;
		cout << "5 - Exportar" << endl;
		cout << "6 - Finalizar" << endl;
		cout << "Digite sua opção: ";
		cin >> opcao;
		cout << "---------------------\n\n" << endl;
		
		string strAux = "";
		int op2 = 0;
	    switch (opcao)
	    {	
	        case 1:
	        {
	        	cout << "\nUsuarios do Sistema" << endl;
	        	//Mostra usuarios Existentes
				contatos.mostrar();
				
				cin.ignore();
	            cout << "Escolha um dos Usuarios para Logar: " ;
	            getline (std::cin,strAux);
	            
	            
	            //strAux = "Chuck Norris";
	            if (contatos.existe(strAux))
				{	
					//pega usuario logado
					pessoaAux = contatos.retornaPessoa(strAux);
    				cout << "Usuario selecionado: " << pessoaAux->getNome() << "\n" << endl;
    				logado = true;
    				
				} else {
					cout << "Usuário não existe" << endl;
				}

	            break;
			}
	        case 2:
	           	cout << "\nUsuario " << pessoaAux-> getNome() << " deslogado!" << endl;
	            //deslogar e desabilitar as funcoes
				logado = false;
				break;
	        case 3:
	        	if (logado)
				{
					
				
		        	while(op2 != 4)
					{	
						cout << "\n---------------------" << endl;
						cout << "Opções de Contato" << endl;
			        	cout << "1 - Listar" << endl;
			        	cout << "2 - Incluir" << endl;
			        	cout << "3 - Excluir" << endl;
			        	cout << "4 - Voltar" << endl;
			        	cout << "Digite sua opção: ";
			        	cin >> op2;
			        	cout << "---------------------\n\n" << endl;
			        	
						switch(op2)
						{
							case 1:
								//Listar: mostra os contatos do usuário logado, bem como os seus interesses/atividades
								cout << "\nContatos de " << pessoaAux->getNome() << endl;
				            	pessoaAux->mostrarContatos();
								break;
							case 2:
							
								strAux = "";
								cin.ignore();
								cout << "Digite o nome do Novo Contato: " << endl;				
				        		getline(cin, strAux);
				        		
				        		//Existe Contato
				        		if (pessoaAux->existePessoa(strAux))
								{	cout << "Essa pessoa já é um Contato! \n" << endl;
								} else {
									if (contatos.existe(strAux))
									{	contatoAux = contatos.retornaPessoa(strAux);
										pessoaAux->addContato(contatoAux);
									} else {
										cout << "Usuário não existe!\n" << endl;
									}
									
								}
				        		break;
							
							case 3:
								//Excluir: permite a exclusão de um contato existente na lista do usuário.
								strAux = "";
								cin.ignore();
								cout << "Digite o nome do Contato a ser Removido: " << endl;				
				        		getline(cin, strAux);
				        		if (contatos.existe(strAux))
								{	pessoaAux->removerContato(strAux);
								} else {
									cout << "Este contato não existe!\n" << endl;
								}
								break;
							
							default:
								cout << "Opção não encontrada!\n" << endl;
								break;
						}	
					}	        	
				} else {
					cout << "É necessário fazer Login!" << endl;
				}
	            
	            break;
	        case 4:
	        	if (logado)
				{
					while(op2 != 4)
					{	
						cout << "Opções de Atividades e Interesses" << endl;
			        	cout << "1 - Listar" << endl;
			        	cout << "2 - Incluir" << endl;
			        	cout << "3 - Excluir" << endl;
			        	cout << "4 - Voltar" << endl;
			        	cout << "Digite sua opção: ";
			        	cin >> op2;
			        	
						switch(op2)
						{
							case 1:
								//Listar: mostra os interesses/atividades do usuário logado
								cout << "\nInteresses de " << pessoaAux->getNome() << endl;
				            	pessoaAux->mostrarInteressesAtividades();
								break;
							case 2:
							
								strAux = "";
								cin.ignore();
								cout << "Digite o nome do Novo Interesse/Atividade: " << endl;				
				        		getline(cin, strAux);
				        		
				        		//Se a pessoa logada, possui esse interesse/atividade
				        		if (pessoaAux->existeInteresseAtividade(strAux))
								{	cout << "Esse Interesse/Atividade já existe no usuário! \n" << endl;
								} 
								else //se a pessoa nao possui esse interesse
								{	//verificar se esse interesse existe na lista de interesses
									if (interessesAtividades.existe(strAux))
									{	//adiciona interesse no meu usuario logado
										interesseAtividadeAux = interessesAtividades.retornaInteresseAtividade(strAux);
					        			//adiciona o interesse no nosso usuario logado
										pessoaAux->addInteresse(interesseAtividadeAux);
									} else {
										cout << "Esse Interesse/Atividade não existe!\n" << endl;
									}
								}
								break;
							
							case 3:
								//Excluir: permite a exclusão de um interesse/atividade existente na lista do usuário.
								strAux = "";
								cin.ignore();
								cout << "Digite o nome do Interesse/Atividade a ser Removido: " << endl;				
				        		getline(cin, strAux);
				        		//Se interesse existe no usuario logado
								
								if (interessesAtividades.existe(strAux))
								{	pessoaAux->removerInteresseAtividades(strAux);
								} else {
									cout << "Este Interesse/Atividade não existe! \n" << endl;
								}
				        		
								break;
							
							default:
								cout << "Opção não Encontrada" << endl;
								break;
						}	
					}
				} else {
					cout << "É necessário fazer Login! " << endl;
				}	        	
	            break;
	        case 5:
	        	cout << "Exportando Arquivo para 'rede.dot'. " << endl;
	        	//usuarios sao os contatos da rede social
	           	criaGraphFile(contatos);
				removeDuplicacoes();
	            break;
	        case 6:
	        	cout << "Saindo do FACINBook" << endl;
	        	
	        	break;
	        default:
	            cout << "Opcao invalida! Informe outro valor." << endl;
	            break;
	    }
	}
	
	int ret = criaRedeFile(contatos);
	if (ret == 0) {
		cout << "Rede salva com Sucesso! " << endl;
	}
	cout << "Até logo" << endl;
	return (0);
}


int main(int argc, char** argv)
{	
	
	
	//Usuarios do sistema
	ListaPessoa contatos;
	std::ifstream file("contatos.txt");
    std::string str; 
    while (std::getline(file, str))
    {	//inserir usuario lido do arquivo no sistema
        contatos.inserir(str);
    }
	
	//Cria Lista de InteressesAtividades
	ListaInteressesAtividades interessesAtividades;
	std::ifstream file2("atividades.txt");
    std::string str2; 
    while (std::getline(file2, str2))
    {
        interessesAtividades.inserir(str2);
    }
	
	
	
	std::ifstream file3("rede.txt");
    std::string str3; 
    int line = 0;
    
    //Usuario Logado
    Pessoa *pessoaAux;
    
    //Contato Para Ser Adiconado no usuario Logado
    Pessoa *contatoAux;
    
    //Intyeresses para ser adicionado ao usuario Logado
    InteresseAtividade *interesseAtividadeAux;
    
    //Tem novo usuario que sera adicionado
    bool nextIsUser = false;
    
    //Cria rede
    do
    {	
		if (str3 != "") 
		{
			if (str3 == "#")
			{	nextIsUser = true;
			} 
			else if((str3[0] == '-') && (str3[1] == '-'))
			{
				contatoAux = contatos.retornaPessoa(substring(str3, "-- "));
				pessoaAux->addContato(contatoAux);
				
			}
        	else if (line == 1)
			{	//Usuario Selecionado como primeiro
				pessoaAux = contatos.retornaPessoa(str3);
			} 
			else if (nextIsUser)
			{	//se tem usuario com esse nome, sera meu usuario a ser Selecionado
				nextIsUser = false;
				pessoaAux = contatos.retornaPessoa(str3);
			}
			else 
			{	//o que nao eh usuario nem contato, é um novo interesse
				if (pessoaAux != NULL)
				{	//adiciona Interesse na pessoa observada
					interesseAtividadeAux = interessesAtividades.retornaInteresseAtividade(str3);
					pessoaAux->addInteresse(interesseAtividadeAux);
				}
			}
		}
		line++;
    }while (std::getline(file3, str3));
	
	
	int ret = menu(contatos, interessesAtividades);
	return ret;
	
	
	
	return 0; 
}