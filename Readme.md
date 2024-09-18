# Problema da Seleção

**Entrada:** Uma sequência de inteiros a<sub>1</sub>,...,a<sub>n</sub> e i tal que 1 ≤ i ≤ n\
**Saída:** O i-esimo menor inteiro da sequência.

Um caso particularmente importante do problema da seleção consiste em encontrar a mediana de uma sequência. Considere as seguinte soluções para esse problema:
 
 Selecao1(A,i)\
    1 Ordene(A)\
    2 return a<sub>i</sub>

 Selecao2(A,i)\
    1 q ← Particao(A)\
    2 if n = 1\
    3   then return a<sub>1</sub>\
    4 if i < q\
    5   then return Selecao2(A[1 : q − 1],i)\
    6 else if i > q\
    7 then return Selecao2(A[q + 1 : n],i −(q + 1))\
    8 else return a<sub>q</sub>

Implemente os dois algoritmos. No primeiro caso, será necessário primeiro implementar um algoritmo de ordenação. Você pode escolher qual implementar desde que seja um dos algoritmos Θ(n.lg(n)) no caso médio.

Escreva um relatório com introdução, objetivo, resultados e conclusão. A introdução deve apresentar o problema da seleção com exemplos de aplicação, um esboço da correção e do tempo de processamento de cada um dos algoritmos. O objetivo deve ser comparar o tempo de processamento em sua máquina para entradas de tamanhos diferentes. Nos resultados deve ser apresentado um gráfico ou uma tabela com o tempo de processamento de cada algoritmo para entradas de diferentes tamanhos. A conclusão deve defender o uso de um deles como mais eficiente. Para gerar os testes vocês podem usar o programa disponibilizado em https://github.com/marciomr/IAA/blob/main/gerador.c.
