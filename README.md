# Projeto de gerenciamento de uma exibidora de cinema

Este projeto consiste em um sistema de gerenciamento para uma exibidora de cinema. 
O sistema deve ser capaz de gerenciar as salas do cinema, suas respectivas sessões, 
bem como a venda de ingressos de acordo com o tipo da sala (IMAX,3D,COMUM) e a disponibilidade dos assentos.

## Autores

* **Andressa Nowasyk** - @andressanowasyk
* **Henrique Lisboa** - @hlisboasousa

## Requisitos para compilação
- Para compilar é necessario ter:

Compilador g++, versão 11

## Como compilar
- Primeiro é necessário clonar o repositório com o comando:
```
git clone 'https://github.com/pds2/20192-team-1.git'
```
- Acessar diretório do projeto:
```
cd 20192-team-1/
```
- No diretório raiz do projeto execute o Makefile com:
```
make
```

## Como executar

- Comando para compilar e executar
```
make run
```
- Comando para rodar os testes
```
make tests
```
- Comando para desfazer compilações anteriores
```
make clean
```
## User Stories

### Vendedor
* Como um vendedor, eu quero ver todos os assentos disponíveis e seus respectivos preços das sessões abertas para a venda para que eu possa mostrar ao cliente.
- [ ] Imprimir assentos disponíveis e vendidos de determinada sessão
- [ ] Imprimir próximas sessões do cinema

* Como um vendedor, eu quero conseguir vender ingressos de assentos disponíveis das sessões abertas para venda.
- [ ] Vender um ingresso do mapa de assento da determinada sessão, transformando-o num assento ocupado.
- [ ] Adicionar na renda do filme, do cinema e do distribuidor o valor adquirido para cada ingresso vendido

### Gerente
* Como um gerente, eu quero ser capaz de adicionar um novo filme para exibição, o horário, a quantidade e o tipo de sala das sessões de cada novo filme.
- [ ] Adicionar um novo distribuidor
- [ ] Adicionar um novo filme para exibição
- [ ] Adicionar uma nova sessão, em determinado horário e sala de determinado filme

* Como gerente, eu quero ser capaz de ver a renda de cada filme para que eu possa decidir ou não criar novas sessões daquele filme.
- [ ] Imprimir cada filme em exibição, sua respectiva verba, ticket médio e público


### Diretor do Cinema
* Como diretor do cinema, eu quero poder criar novas salas, criar novos gerentes e novos vendedores.
- [ ] Criar novas salas e setar suas capacidades
- [ ] Criar novos empregados para o cinema

## Cartões CRC

O cinema é composto por salas que, por sua vez, compoem sessões através de filmes. A sessão possui uma quantidade de assentos definido pela sala escolhida, um horário e um filme.
Os assentos das sessões são vendidos em formas de ingresso e, acada venda de assento, é mudado o estado do mesmo de livre para ocupado.
A cada venda de ingresso de determinada sessão é necessário guardar o valor do ingresso na arrecadação do filme, no caixa do cinema e a devida porcentagem para o distribuidor cujo filme foi negociado.
Os usuários que compoem o sistema são: dono do cinema, gerente, vendedor e distribuidor. Cada um possui um nível de acesso para que cada um consiga acessar somente determinadas funcionalidades do sistema. 


| Classe: Pessoa                            |                       |
|-------------------------------------------|-----------------------|
| Responsabilidades:                        | Colaborações:         |
|   *Saber seu nome*;                       |                       |
|   *Saber seu cpf*;                        |                       |
|   *Saber seu nível*;                      |                       |


| Classe: Cinema                                |                       |
|-----------------------------------------------|-----------------------|
| Responsabilidades:                            | Colaborações:         |
|   *Ser capaz de adicionar salas*;             |  *Sala*               |
|   *Ser capaz de adicionar filmes*;            |  *Filme*              |
|   *Ser capaz adicionar sessões*;              |  *Sessão*             |
|   *Ser capaz de adicionar distribuidor*;      |  *Pessoa*             |
|   *Saber filmes em cartaz*;                   |                       |
|   *Saber valor total já arrecadado*;          |                       |
|   *Conhecer todas suas salas*;                |                       |
|   *Conhecer todos os seus filmes*;            |                       |
|   *Conhecer todas as suas sessões*;           |                       |
|   *Conhecer todos os seus empregados*;        |                       |
|   *Ser capaz de adicionar um novo empregado*; |                       |


| Classe: Sala                                        |               |
|-----------------------------------------------------|---------------|
| Responsabilidades:                                  | Colaborações: |
|   *Saber sua quantidade de fileiras*;               |               |
|   *Saber sua quantidade de assentos por fileiras*;  |               |
|   *Saber seu valor por assento*;                    |               |
|   *Saber seu tipo*;                                 |               |


| Classe: Assento                     |               | 
|-------------------------------------|---------------|
| Responsabilidades:                  | Colaborações: |
|   *Saber se está ocupado ou livre*; |               |
|   *Ser capaz de setar seu estado*;  |               |


| Classe: Filme                                             |                 |
|-----------------------------------------------------------|-----------------|
| Responsabilidades:                                        | Colaborações:   |
|   *Saber sua duração*;                                    | *Distribuidor*; |
|   *Saber seu título*;                                     |                 |
|   *Saber sua verba arrecadada*;                           |                 |
|   *Saber o distribuidor que negociou*;                    |                 |
|   *Saber sua bilheteria total*;                           |                 |
|   *Saber seu público total*;                              |                 |
|   *Saber seu tícket médio*;                               |                 |
|   *Ser capaz de adicionar valor na sua verba arrecadada*; |                 |


| Classe: Sessão                                                                  |                 |
|---------------------------------------------------------------------------------|-----------------|
| Responsabilidades:                                                              | Colaborações:   |
|   *Saber sua data/hora*;                                                        |  *Sala*         |
|   *Saber seu filme*;                                                            |  *Filme*        |
|   *Ser capaz de criar seu mapa de assentos de acordo com a capacidade da sala*; |  *Assento*      |
|   *Ser capaz de ver assentos*;                                                  |                 |
|   *Ser capaz de imprimir o mapa de assentos (livres/ocupados)*;                 |                 |


| Classe: IMAX                                                                    | Superclasse: Sala |
|---------------------------------------------------------------------------------|-------------------|
| Responsabilidades:                                                              | Colaborações:     |
|   *Ser capaz de adicionar uma taxa no valor do ingresso*;                       |                   |                 
|   *Saber sua taxa*;                                                   |                   |    


| Classe: Premium                                                                 | Superclasse: IMAX |
|---------------------------------------------------------------------------------|-------------------|
| Responsabilidades:                                                              | Colaborações:     |
|   *Ser capaz de adicionar uma taxa no valor do ingresso*;                       |                   |                 
|   *Saber sua taxa*;                                                             |                   |   
  

| Classe: 3D                                                                      | Superclasse: IMAX |
|---------------------------------------------------------------------------------|-------------------|
| Responsabilidades:                                                              | Colaborações:     |
|   *Ser capaz de adicionar uma taxa no valor do ingresso*;                       |                   |                 
|   *Saber sua taxa*;                                                             |                   |  
