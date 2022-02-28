Para a construção dos modelos de simulação de um possível cruzamento em X de ruas de faixa simples, foi decidido implementar um algoritmo em linguagem C para cada modelo. Basicamente temos que imaginar o cruzamento em X como um sistema A: apresentando uma entrada única e saída única (referente a sua Fila de Veículos A), e um Sistema B: apresentando uma entrada única e saída única (referente a sua Fila de Veículos B). Ambos os sistemas são servidos por um controlador de trânsito(semáforo) presente no ponto de intersecção do cruzamento entre as duas Ruas A e B. 

A entrada dos sistemas é alimentada por um gerador de veículos, o qual gera um número aleatório entre 0 e 4 veículos/ unidade de tempo. Para entender o funcionamento deste gerador de veículo é preciso explicar com um exemplo. Se o gerador sortear o número 2, quer dizer que naquele período de tempo foi gerado dois veículos e assim foi adicionado a fila de veículos em questão. O que precisa estar claro é que o usuário decido qual passo de tempo e unidade de tempo aquela simulação vai representar. Se foi escolhido um passo de tempo a cada 1min, cada iteração representará um comportamento a cada 1 min. Se houve 200 iterações, neste caso foi simulado durante 200 min, assim cada iteração representa 1 min. Então o gerador de veículos representará a taxa de entrada de veículos naquele período de tempo na fila do sistema. A outra parte do sistema é representada pela fila de veículos, representada pelos clientes a serem servidos pelo servidor. Para representar o comportamento de saída de veículos da fila, foi implementado uma função semelhante ao gerador de veículos, a qual sorteia um número aleatório entre 0 e 9 para representar a taxa de saída/ período de tempo. Se foi sorteado o número 6 naquele período, isto quer dizer que a taxa de saída de veículos daquela fila foi de 6 veículos/período tempo. Agora imagine a seguinte situação: a fila de uma rua apresenta 5 veículos. Estamos analisando o comportamento a cada 1 minuto. O gerador de veículos sorteou o número 4, 4 veículos/1 min e assim durante 1 min foi adicionado 4 veículos na fila de veículos. Agora a fila apresenta o tamanho 9. Para a saída do sistema, a taxa de saída foi 6 veículos/1min, assim a fila no final de 1 min apresentará o tamanho 9-6 = 3 veículos. 

Para diferenciar os modelos, foi adotado políticas de abertura e fechamento de semáforo, diferentes. Para o primeiro modelo nomeado por: “Modelo_Tamanho_Fila”, foi adotado uma política baseada no tamanho de fila. Não apresenta tempo mínimo de aberto e tempo máximo de fechado, temos uma função que observa o ambiente em questão e verifica assim qual rua apresenta o maior tamanho de fila (maior número de veículos). Após esta observação, a informação constatada será repassada para o controlador, e então ele vai deixar aberto o semáforo para a fila de maior tamanho. Para explicar este funcionamento, você tem que imaginar a seguinte situação: A fila A apresenta 5 veículos e a fila B apresenta 7 veículos. O ambiente está sendo observado e então foi verificado que a fila B apresenta um tamanho maior que a fila A (fila_B>fila_A). O semáforo só ficar verde para a fila A quando a fila A ser maior que a fila B. Se as filas tiverem um tamanho igual será então decidido a abertura por um sorteio, mas só se tiverem tamanho igual em algum momento.

Quando um semáforo está aberto, há taxa de entrada e saída para fila que apresenta semáforo aberto e apenas taxa de entrada para a fila com o semáforo fechado. 

Ações deste modelo

1-      Gerar número de veículos inicias para as filas

2-      Função ambiente_observacao() irá verificar a maior fila

3-      Função controlador(obs), irá deixar aberto para a maior fila verificada na função ambiente_observacao()

4-      Na função ambiente_simul é onde representa a simulação do ambiente modelado (cruzamento em X). Lá veículos são adicionados e retirados das filas.

O modelo 2 é aquele que o controle de abertura e fechamento de semáforo é feito de maneira aleatória, ou seja, será sorteado qual semáforo deverá ficar aberto naquele período de tempo. Enquanto o semáforo está aberto haverá taxa de entrada e saída para o semáforo aberto e apenas taxa de entrada para o semáforo fechado.

 

O modelo 3 tem a seguinte política, deixar o semáforo da fila A aberto por um período de tempo fixo e o semáforo B fechado por um períodos de tempo fixo. Depois o semáforo B estará aberto por um período de tempo fixo e o semáforo A ficará fechado por um período de tempo fixo, e assim por diante. Aqui não será verificado em nenhum momento o tamanho de fila de veículos. Haverá então tempo fixo de aberto e fechado para os semáforos. Enquanto o semáforo está aberto haverá taxa de entrada e saída para o semáforo aberto e apenas taxa de entrada para o semáforo fechado.

Simulação dos modelos desenvolvidos em linguagem C:

 

 

**1 – Modelo tamanho de fila:**

Tentativa( 1)  Média Veículo A: 5.000000,Média Veiculo B: 4.108333 por 240 periodos de tempo

Tentativa( 2)  Média Veículo A: 3.945833,Média Veiculo B: 4.016667 por 240 periodos de tempo

Tentativa( 3)  Média Veículo A: 3.587500,Média Veiculo B: 4.058333 por 240 periodos de tempo

Tentativa( 4)  Média Veículo A: 5.033333,Média Veiculo B: 5.641667 por 240 periodos de tempo

Tentativa( 5)  Média Veículo A: 2.833333,Média Veiculo B: 2.354167 por 240 periodos de tempo

Tentativa( 6)  Média Veículo A: 5.783333,Média Veiculo B: 5.670833 por 240 periodos de tempo

Tentativa( 7)  Média Veículo A: 5.800000,Média Veiculo B: 5.725000 por 240 periodos de tempo

Tentativa( 8)  Média Veículo A: 5.829167,Média Veiculo B: 4.987500 por 240 periodos de tempo

Tentativa( 9)  Média Veículo A: 3.070833,Média Veiculo B: 2.416667 por 240 periodos de tempo

Tentativa( 10)  Média Veículo A: 4.983333,Média Veiculo B: 4.012500 por 240 periodos de tempo

Tentativa( 11)  Média Veículo A: 3.412500,Média Veiculo B: 3.362500 por 240 periodos de tempo

Tentativa( 12)  Média Veículo A: 3.700000,Média Veiculo B: 3.112500 por 240 periodos de tempo

Tentativa( 13)  Média Veículo A: 3.133333,Média Veiculo B: 3.316667 por 240 periodos de tempo

Tentativa( 14)  Média Veículo A: 4.487500,Média Veiculo B: 4.170833 por 240 periodos de tempo

Tentativa( 15)  Média Veículo A: 4.225000,Média Veiculo B: 3.858333 por 240 periodos de tempo

Tentativa( 16)  Média Veículo A: 5.070833,Média Veiculo B: 4.733333 por 240 periodos de tempo

Tentativa( 17)  Média Veículo A: 3.125000,Média Veiculo B: 3.362500 por 240 periodos de tempo

Tentativa( 18)  Média Veículo A: 4.616667,Média Veiculo B: 5.850000 por 240 periodos de tempo

Tentativa( 19)  Média Veículo A: 3.658333,Média Veiculo B: 3.483333 por 240 periodos de tempo

Tentativa( 20)  Média Veículo A: 3.750000,Média Veiculo B: 4.483333 por 240 periodos de tempo

Tentativa( 21)  Média Veículo A: 3.437500,Média Veiculo B: 3.279167 por 240 periodos de tempo

Tentativa( 22)  Média Veículo A: 4.229167,Média Veiculo B: 4.729167 por 240 periodos de tempo

Tentativa( 23)  Média Veículo A: 3.616667,Média Veiculo B: 4.204167 por 240 periodos de tempo

Tentativa( 24)  Média Veículo A: 4.454167,Média Veiculo B: 4.391667 por 240 periodos de tempo

Tentativa( 25)  Média Veículo A: 5.183333,Média Veiculo B: 5.295833 por 240 periodos de tempo

Tentativa( 26)  Média Veículo A: 4.770833,Média Veiculo B: 4.412500 por 240 periodos de tempo

Tentativa( 27)  Média Veículo A: 3.829167,Média Veiculo B: 3.833333 por 240 periodos de tempo

Tentativa( 28)  Média Veículo A: 4.270833,Média Veiculo B: 4.629167 por 240 periodos de tempo

Tentativa( 29)  Média Veículo A: 4.779167,Média Veiculo B: 4.225000 por 240 periodos de tempo

Tentativa( 30)  Média Veículo A: 5.429167,Média Veiculo B: 5.366667 por 240 periodos de tempo

Tentativa( 31)  Média Veículo A: 2.575000,Média Veiculo B: 3.291667 por 240 periodos de tempo

Tentativa( 32)  Média Veículo A: 3.733333,Média Veiculo B: 3.920833 por 240 periodos de tempo

Tentativa( 33)  Média Veículo A: 4.629167,Média Veiculo B: 5.091667 por 240 periodos de tempo

Tentativa( 34)  Média Veículo A: 3.454167,Média Veiculo B: 3.120833 por 240 periodos de tempo

Tentativa( 35)  Média Veículo A: 4.104167,Média Veiculo B: 4.241667 por 240 periodos de tempo

Tentativa( 36)  Média Veículo A: 3.883333,Média Veiculo B: 4.300000 por 240 periodos de tempo

Tentativa( 37)  Média Veículo A: 4.033333,Média Veiculo B: 5.312500 por 240 periodos de tempo

Tentativa( 38)  Média Veículo A: 5.483333,Média Veiculo B: 4.033333 por 240 periodos de tempo

Tentativa( 39)  Média Veículo A: 4.229167,Média Veiculo B: 3.687500 por 240 periodos de tempo

Tentativa( 40)  Média Veículo A: 4.779167,Média Veiculo B: 6.416667 por 240 periodos de tempo

Tentativa( 41)  Média Veículo A: 3.570833,Média Veiculo B: 3.866667 por 240 periodos de tempo

Tentativa( 42)  Média Veículo A: 4.337500,Média Veiculo B: 4.337500 por 240 periodos de tempo

Tentativa( 43)  Média Veículo A: 2.604167,Média Veiculo B: 2.670833 por 240 periodos de tempo

Tentativa( 44)  Média Veículo A: 4.341667,Média Veiculo B: 4.062500 por 240 periodos de tempo

Tentativa( 45)  Média Veículo A: 5.133333,Média Veiculo B: 5.733333 por 240 periodos de tempo

Tentativa( 46)  Média Veículo A: 5.029167,Média Veiculo B: 5.558333 por 240 periodos de tempo

Tentativa( 47)  Média Veículo A: 5.537500,Média Veiculo B: 5.504167 por 240 periodos de tempo

Tentativa( 48)  Média Veículo A: 4.404167,Média Veiculo B: 4.816667 por 240 periodos de tempo

Tentativa( 49)  Média Veículo A: 5.495833,Média Veiculo B: 6.341667 por 240 periodos de tempo

Tentativa( 50)  Média Veículo A: 5.766667,Média Veiculo B: 5.479167 por 240 periodos de tempo

Tentativa( 51)  Média Veículo A: 4.229167,Média Veiculo B: 3.950000 por 240 periodos de tempo

Tentativa( 52)  Média Veículo A: 4.700000,Média Veiculo B: 4.412500 por 240 periodos de tempo

Tentativa( 53)  Média Veículo A: 3.941667,Média Veiculo B: 3.604167 por 240 periodos de tempo

Tentativa( 54)  Média Veículo A: 5.333333,Média Veiculo B: 5.587500 por 240 periodos de tempo

Tentativa( 55)  Média Veículo A: 2.425000,Média Veiculo B: 2.512500 por 240 periodos de tempo

Tentativa( 56)  Média Veículo A: 4.204167,Média Veiculo B: 4.316667 por 240 periodos de tempo

Tentativa( 57)  Média Veículo A: 3.825000,Média Veiculo B: 3.737500 por 240 periodos de tempo

Tentativa( 58)  Média Veículo A: 3.795833,Média Veiculo B: 4.325000 por 240 periodos de tempo

Tentativa( 59)  Média Veículo A: 4.216667,Média Veiculo B: 3.500000 por 240 periodos de tempo

Tentativa( 60)  Média Veículo A: 3.529167,Média Veiculo B: 3.429167 por 240 periodos de tempo

Tentativa( 61)  Média Veículo A: 4.141667,Média Veiculo B: 3.200000 por 240 periodos de tempo

Tentativa( 62)  Média Veículo A: 4.112500,Média Veiculo B: 4.041667 por 240 periodos de tempo

Tentativa( 63)  Média Veículo A: 4.104167,Média Veiculo B: 3.695833 por 240 periodos de tempo

Tentativa( 64)  Média Veículo A: 4.712500,Média Veiculo B: 4.237500 por 240 periodos de tempo

Tentativa( 65)  Média Veículo A: 3.462500,Média Veiculo B: 4.633333 por 240 periodos de tempo

Tentativa( 66)  Média Veículo A: 4.783333,Média Veiculo B: 5.050000 por 240 periodos de tempo

Tentativa( 67)  Média Veículo A: 5.083333,Média Veiculo B: 4.895833 por 240 periodos de tempo

Tentativa( 68)  Média Veículo A: 2.954167,Média Veiculo B: 3.433333 por 240 periodos de tempo

Tentativa( 69)  Média Veículo A: 4.104167,Média Veiculo B: 4.408333 por 240 periodos de tempo

Tentativa( 70)  Média Veículo A: 5.175000,Média Veiculo B: 5.216667 por 240 periodos de tempo

Tentativa( 71)  Média Veículo A: 4.525000,Média Veiculo B: 4.525000 por 240 periodos de tempo

Tentativa( 72)  Média Veículo A: 3.262500,Média Veiculo B: 2.700000 por 240 periodos de tempo

Tentativa( 73)  Média Veículo A: 4.137500,Média Veiculo B: 4.425000 por 240 periodos de tempo

Tentativa( 74)  Média Veículo A: 5.345833,Média Veiculo B: 6.083333 por 240 periodos de tempo

Tentativa( 75)  Média Veículo A: 4.516667,Média Veiculo B: 4.641667 por 240 periodos de tempo

Tentativa( 76)  Média Veículo A: 3.891667,Média Veiculo B: 4.487500 por 240 periodos de tempo

Tentativa( 77)  Média Veículo A: 4.066667,Média Veiculo B: 3.587500 por 240 periodos de tempo

Tentativa( 78)  Média Veículo A: 5.679167,Média Veiculo B: 6.508333 por 240 periodos de tempo

Tentativa( 79)  Média Veículo A: 6.845833,Média Veiculo B: 6.654167 por 240 periodos de tempo

Tentativa( 80)  Média Veículo A: 3.479167,Média Veiculo B: 2.966667 por 240 periodos de tempo

Tentativa( 81)  Média Veículo A: 4.729167,Média Veiculo B: 5.766667 por 240 periodos de tempo

Tentativa( 82)  Média Veículo A: 3.729167,Média Veiculo B: 4.016667 por 240 periodos de tempo

Tentativa( 83)  Média Veículo A: 3.570833,Média Veiculo B: 4.045833 por 240 periodos de tempo

Tentativa( 84)  Média Veículo A: 3.908333,Média Veiculo B: 2.820833 por 240 periodos de tempo

Tentativa( 85)  Média Veículo A: 3.312500,Média Veiculo B: 3.587500 por 240 periodos de tempo

Tentativa( 86)  Média Veículo A: 3.366667,Média Veiculo B: 3.016667 por 240 periodos de tempo

Tentativa( 87)  Média Veículo A: 5.029167,Média Veiculo B: 5.179167 por 240 periodos de tempo

Tentativa( 88)  Média Veículo A: 4.708333,Média Veiculo B: 4.300000 por 240 periodos de tempo

Tentativa( 89)  Média Veículo A: 3.808333,Média Veiculo B: 3.741667 por 240 periodos de tempo

Tentativa( 90)  Média Veículo A: 5.537500,Média Veiculo B: 5.308333 por 240 periodos de tempo

Tentativa( 91)  Média Veículo A: 4.300000,Média Veiculo B: 3.570833 por 240 periodos de tempo

Tentativa( 92)  Média Veículo A: 4.245833,Média Veiculo B: 2.812500 por 240 periodos de tempo

Tentativa( 93)  Média Veículo A: 4.033333,Média Veiculo B: 3.766667 por 240 periodos de tempo

Tentativa( 94)  Média Veículo A: 4.250000,Média Veiculo B: 4.233333 por 240 periodos de tempo

Tentativa( 95)  Média Veículo A: 4.541667,Média Veiculo B: 5.850000 por 240 periodos de tempo

Tentativa( 96)  Média Veículo A: 3.554167,Média Veiculo B: 4.425000 por 240 periodos de tempo

Tentativa( 97)  Média Veículo A: 5.358333,Média Veiculo B: 4.133333 por 240 periodos de tempo

Tentativa( 98)  Média Veículo A: 5.675000,Média Veiculo B: 4.500000 por 240 periodos de tempo

Tentativa( 99)  Média Veículo A: 5.158333,Média Veiculo B: 4.725000 por 240 periodos de tempo

Tentativa( 100)  Média Veículo A: 4.604167,Média Veiculo B: 4.175000 por 240 periodos de tempo

Média Veículo A: 3.850000,Média Veiculo B: 3.860000 por 240 períodos de tempo em 100 tentativas

 

 

 

 

 

 

**2- Modelo controle Aleatório**

Tentativa( 1)  Média Veículo A: 10.220834,Média Veiculo B: 7.216667 por 240 periodos de tempo

Tentativa( 2)  Média Veículo A: 5.154167,Média Veiculo B: 11.608334 por 240 periodos de tempo

Tentativa( 3)  Média Veículo A: 13.912500,Média Veiculo B: 5.191667 por 240 periodos de tempo

Tentativa( 4)  Média Veículo A: 5.829167,Média Veiculo B: 6.137500 por 240 periodos de tempo

Tentativa( 5)  Média Veículo A: 10.754167,Média Veiculo B: 6.629167 por 240 periodos de tempo

Tentativa( 6)  Média Veículo A: 5.808333,Média Veiculo B: 6.908333 por 240 periodos de tempo

Tentativa( 7)  Média Veículo A: 4.858333,Média Veiculo B: 9.083333 por 240 periodos de tempo

Tentativa( 8)  Média Veículo A: 6.629167,Média Veiculo B: 8.400000 por 240 periodos de tempo

Tentativa( 9)  Média Veículo A: 9.233334,Média Veiculo B: 5.016667 por 240 periodos de tempo

Tentativa( 10)  Média Veículo A: 5.579167,Média Veiculo B: 9.175000 por 240 periodos de tempo

Tentativa( 11)  Média Veículo A: 11.308333,Média Veiculo B: 5.887500 por 240 periodos de tempo

Tentativa( 12)  Média Veículo A: 4.900000,Média Veiculo B: 11.641666 por 240 periodos de tempo

Tentativa( 13)  Média Veículo A: 9.929167,Média Veiculo B: 7.150000 por 240 periodos de tempo

Tentativa( 14)  Média Veículo A: 6.004167,Média Veiculo B: 5.400000 por 240 periodos de tempo

Tentativa( 15)  Média Veículo A: 14.454166,Média Veiculo B: 8.554167 por 240 periodos de tempo

Tentativa( 16)  Média Veículo A: 9.666667,Média Veiculo B: 9.387500 por 240 periodos de tempo

Tentativa( 17)  Média Veículo A: 7.825000,Média Veiculo B: 9.241667 por 240 periodos de tempo

Tentativa( 18)  Média Veículo A: 7.445833,Média Veiculo B: 6.258333 por 240 periodos de tempo

Tentativa( 19)  Média Veículo A: 8.083333,Média Veiculo B: 9.033334 por 240 periodos de tempo

Tentativa( 20)  Média Veículo A: 10.183333,Média Veiculo B: 7.779167 por 240 periodos de tempo

Tentativa( 21)  Média Veículo A: 4.950000,Média Veiculo B: 9.937500 por 240 periodos de tempo

Tentativa( 22)  Média Veículo A: 6.095833,Média Veiculo B: 14.833333 por 240 periodos de tempo

Tentativa( 23)  Média Veículo A: 7.800000,Média Veiculo B: 8.120833 por 240 periodos de tempo

Tentativa( 24)  Média Veículo A: 3.487500,Média Veiculo B: 17.183332 por 240 periodos de tempo

Tentativa( 25)  Média Veículo A: 5.729167,Média Veiculo B: 6.387500 por 240 periodos de tempo

Tentativa( 26)  Média Veículo A: 6.337500,Média Veiculo B: 11.008333 por 240 periodos de tempo

Tentativa( 27)  Média Veículo A: 7.462500,Média Veiculo B: 10.466666 por 240 periodos de tempo

Tentativa( 28)  Média Veículo A: 6.679167,Média Veiculo B: 6.983333 por 240 periodos de tempo

Tentativa( 29)  Média Veículo A: 5.379167,Média Veiculo B: 8.812500 por 240 periodos de tempo

Tentativa( 30)  Média Veículo A: 8.075000,Média Veiculo B: 9.666667 por 240 periodos de tempo

Tentativa( 31)  Média Veículo A: 6.445833,Média Veiculo B: 6.233333 por 240 periodos de tempo

Tentativa( 32)  Média Veículo A: 9.745833,Média Veiculo B: 4.583333 por 240 periodos de tempo

Tentativa( 33)  Média Veículo A: 14.712500,Média Veiculo B: 7.850000 por 240 periodos de tempo

Tentativa( 34)  Média Veículo A: 7.879167,Média Veiculo B: 7.425000 por 240 periodos de tempo

Tentativa( 35)  Média Veículo A: 9.625000,Média Veiculo B: 8.645833 por 240 periodos de tempo

Tentativa( 36)  Média Veículo A: 10.195833,Média Veiculo B: 7.725000 por 240 periodos de tempo

Tentativa( 37)  Média Veículo A: 11.670834,Média Veiculo B: 5.475000 por 240 periodos de tempo

Tentativa( 38)  Média Veículo A: 5.425000,Média Veiculo B: 6.087500 por 240 periodos de tempo

Tentativa( 39)  Média Veículo A: 13.741667,Média Veiculo B: 6.208333 por 240 periodos de tempo

Tentativa( 40)  Média Veículo A: 10.862500,Média Veiculo B: 8.241667 por 240 periodos de tempo

Tentativa( 41)  Média Veículo A: 5.612500,Média Veiculo B: 9.900000 por 240 periodos de tempo

Tentativa( 42)  Média Veículo A: 5.516667,Média Veiculo B: 7.187500 por 240 periodos de tempo

Tentativa( 43)  Média Veículo A: 7.933333,Média Veiculo B: 10.733334 por 240 periodos de tempo

Tentativa( 44)  Média Veículo A: 5.220833,Média Veiculo B: 14.908334 por 240 periodos de tempo

Tentativa( 45)  Média Veículo A: 7.737500,Média Veiculo B: 5.579167 por 240 periodos de tempo

Tentativa( 46)  Média Veículo A: 21.179167,Média Veiculo B: 8.679167 por 240 periodos de tempo

Tentativa( 47)  Média Veículo A: 8.804167,Média Veiculo B: 4.191667 por 240 periodos de tempo

Tentativa( 48)  Média Veículo A: 9.908334,Média Veiculo B: 6.441667 por 240 periodos de tempo

Tentativa( 49)  Média Veículo A: 9.254167,Média Veiculo B: 5.016667 por 240 periodos de tempo

Tentativa( 50)  Média Veículo A: 8.929167,Média Veiculo B: 7.962500 por 240 periodos de tempo

Tentativa( 51)  Média Veículo A: 9.725000,Média Veiculo B: 12.937500 por 240 periodos de tempo

Tentativa( 52)  Média Veículo A: 6.362500,Média Veiculo B: 6.241667 por 240 periodos de tempo

Tentativa( 53)  Média Veículo A: 9.170834,Média Veiculo B: 8.012500 por 240 periodos de tempo

Tentativa( 54)  Média Veículo A: 5.195833,Média Veiculo B: 10.108334 por 240 periodos de tempo

Tentativa( 55)  Média Veículo A: 26.533333,Média Veiculo B: 10.687500 por 240 periodos de tempo

Tentativa( 56)  Média Veículo A: 8.308333,Média Veiculo B: 8.670834 por 240 periodos de tempo

Tentativa( 57)  Média Veículo A: 10.054167,Média Veiculo B: 7.162500 por 240 periodos de tempo

Tentativa( 58)  Média Veículo A: 11.412500,Média Veiculo B: 11.008333 por 240 periodos de tempo

Tentativa( 59)  Média Veículo A: 7.879167,Média Veiculo B: 6.995833 por 240 periodos de tempo

Tentativa( 60)  Média Veículo A: 5.020833,Média Veiculo B: 10.645833 por 240 periodos de tempo

Tentativa( 61)  Média Veículo A: 12.604167,Média Veiculo B: 6.737500 por 240 periodos de tempo

Tentativa( 62)  Média Veículo A: 9.470834,Média Veiculo B: 5.979167 por 240 periodos de tempo

Tentativa( 63)  Média Veículo A: 7.591667,Média Veiculo B: 8.645833 por 240 periodos de tempo

Tentativa( 64)  Média Veículo A: 6.629167,Média Veiculo B: 10.333333 por 240 periodos de tempo

Tentativa( 65)  Média Veículo A: 8.070833,Média Veiculo B: 4.495833 por 240 periodos de tempo

Tentativa( 66)  Média Veículo A: 8.954166,Média Veiculo B: 10.700000 por 240 periodos de tempo

Tentativa( 67)  Média Veículo A: 8.579166,Média Veiculo B: 11.216666 por 240 periodos de tempo

Tentativa( 68)  Média Veículo A: 6.625000,Média Veiculo B: 5.141667 por 240 periodos de tempo

Tentativa( 69)  Média Veículo A: 12.150000,Média Veiculo B: 7.925000 por 240 periodos de tempo

Tentativa( 70)  Média Veículo A: 4.829167,Média Veiculo B: 9.316667 por 240 periodos de tempo

Tentativa( 71)  Média Veículo A: 7.991667,Média Veiculo B: 6.795833 por 240 periodos de tempo

Tentativa( 72)  Média Veículo A: 6.320833,Média Veiculo B: 5.558333 por 240 periodos de tempo

Tentativa( 73)  Média Veículo A: 8.170834,Média Veiculo B: 6.283333 por 240 periodos de tempo

Tentativa( 74)  Média Veículo A: 3.700000,Média Veiculo B: 6.487500 por 240 periodos de tempo

Tentativa( 75)  Média Veículo A: 13.762500,Média Veiculo B: 10.162500 por 240 periodos de tempo

Tentativa( 76)  Média Veículo A: 6.925000,Média Veiculo B: 8.570833 por 240 periodos de tempo

Tentativa( 77)  Média Veículo A: 6.483333,Média Veiculo B: 12.670834 por 240 periodos de tempo

Tentativa( 78)  Média Veículo A: 6.250000,Média Veiculo B: 7.937500 por 240 periodos de tempo

Tentativa( 79)  Média Veículo A: 9.329166,Média Veiculo B: 7.045833 por 240 periodos de tempo

Tentativa( 80)  Média Veículo A: 9.120833,Média Veiculo B: 6.379167 por 240 periodos de tempo

Tentativa( 81)  Média Veículo A: 7.912500,Média Veiculo B: 5.579167 por 240 periodos de tempo

Tentativa( 82)  Média Veículo A: 6.141667,Média Veiculo B: 10.945833 por 240 periodos de tempo

Tentativa( 83)  Média Veículo A: 4.633333,Média Veiculo B: 8.887500 por 240 periodos de tempo

Tentativa( 84)  Média Veículo A: 10.537500,Média Veiculo B: 13.566667 por 240 periodos de tempo

Tentativa( 85)  Média Veículo A: 5.245833,Média Veiculo B: 9.729167 por 240 periodos de tempo

Tentativa( 86)  Média Veículo A: 6.916667,Média Veiculo B: 4.437500 por 240 periodos de tempo

Tentativa( 87)  Média Veículo A: 6.404167,Média Veiculo B: 15.100000 por 240 periodos de tempo

Tentativa( 88)  Média Veículo A: 8.650000,Média Veiculo B: 6.395833 por 240 periodos de tempo

Tentativa( 89)  Média Veículo A: 2.237500,Média Veiculo B: 10.879167 por 240 periodos de tempo

Tentativa( 90)  Média Veículo A: 8.662500,Média Veiculo B: 8.162500 por 240 periodos de tempo

Tentativa( 91)  Média Veículo A: 8.379167,Média Veiculo B: 4.495833 por 240 periodos de tempo

Tentativa( 92)  Média Veículo A: 8.516666,Média Veiculo B: 7.862500 por 240 periodos de tempo

Tentativa( 93)  Média Veículo A: 9.729167,Média Veiculo B: 7.833333 por 240 periodos de tempo

Tentativa( 94)  Média Veículo A: 7.170833,Média Veiculo B: 8.087500 por 240 periodos de tempo

Tentativa( 95)  Média Veículo A: 5.779167,Média Veiculo B: 8.025000 por 240 periodos de tempo

Tentativa( 96)  Média Veículo A: 7.362500,Média Veiculo B: 11.983334 por 240 periodos de tempo

Tentativa( 97)  Média Veículo A: 5.820833,Média Veiculo B: 8.691667 por 240 periodos de tempo

Tentativa( 98)  Média Veículo A: 12.204166,Média Veiculo B: 5.120833 por 240 periodos de tempo

Tentativa( 99)  Média Veículo A: 5.491667,Média Veiculo B: 7.533333 por 240 periodos de tempo

Tentativa( 100)  Média Veículo A: 4.762500,Média Veiculo B: 8.987500 por 240 periodos de tempo

Média Veículo A: 7.730000,Média Veiculo B: 7.820000 por 240 períodos de tempo em 100 tentativas

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

**3 – Modelo tempo fixo: A: Tempo Aberto = 30, B Tempo Aberto = 30**

 

Tentativa( 1)  Média Veículo A: 22.779167,Média Veiculo B: 25.029167 por 240 periodos de tempo

Tentativa( 2)  Média Veículo A: 22.654167,Média Veiculo B: 25.329166 por 240 periodos de tempo

Tentativa( 3)  Média Veículo A: 23.379168,Média Veiculo B: 24.066668 por 240 periodos de tempo

Tentativa( 4)  Média Veículo A: 24.508333,Média Veiculo B: 21.404167 por 240 periodos de tempo

Tentativa( 5)  Média Veículo A: 24.345833,Média Veiculo B: 22.858334 por 240 periodos de tempo

Tentativa( 6)  Média Veículo A: 23.162500,Média Veiculo B: 21.595833 por 240 periodos de tempo

Tentativa( 7)  Média Veículo A: 22.883333,Média Veiculo B: 28.195833 por 240 periodos de tempo

Tentativa( 8)  Média Veículo A: 20.225000,Média Veiculo B: 18.766666 por 240 periodos de tempo

Tentativa( 9)  Média Veículo A: 23.516666,Média Veiculo B: 24.225000 por 240 periodos de tempo

Tentativa( 10)  Média Veículo A: 24.674999,Média Veiculo B: 21.283333 por 240 periodos de tempo

Tentativa( 11)  Média Veículo A: 23.541666,Média Veiculo B: 22.562500 por 240 periodos de tempo

Tentativa( 12)  Média Veículo A: 25.291666,Média Veiculo B: 27.308332 por 240 periodos de tempo

Tentativa( 13)  Média Veículo A: 28.841667,Média Veiculo B: 29.487499 por 240 periodos de tempo

Tentativa( 14)  Média Veículo A: 28.475000,Média Veiculo B: 25.608334 por 240 periodos de tempo

Tentativa( 15)  Média Veículo A: 22.604166,Média Veiculo B: 20.637501 por 240 periodos de tempo

Tentativa( 16)  Média Veículo A: 27.533333,Média Veiculo B: 29.945833 por 240 periodos de tempo

Tentativa( 17)  Média Veículo A: 19.120832,Média Veiculo B: 23.704166 por 240 periodos de tempo

Tentativa( 18)  Média Veículo A: 21.504168,Média Veiculo B: 24.650000 por 240 periodos de tempo

Tentativa( 19)  Média Veículo A: 23.687500,Média Veiculo B: 25.808332 por 240 periodos de tempo

Tentativa( 20)  Média Veículo A: 24.766666,Média Veiculo B: 24.370832 por 240 periodos de tempo

Tentativa( 21)  Média Veículo A: 19.070833,Média Veiculo B: 31.975000 por 240 periodos de tempo

Tentativa( 22)  Média Veículo A: 24.420834,Média Veiculo B: 24.466667 por 240 periodos de tempo

Tentativa( 23)  Média Veículo A: 22.683332,Média Veiculo B: 24.720833 por 240 periodos de tempo

Tentativa( 24)  Média Veículo A: 24.658333,Média Veiculo B: 19.937500 por 240 periodos de tempo

Tentativa( 25)  Média Veículo A: 19.887501,Média Veiculo B: 24.891666 por 240 periodos de tempo

Tentativa( 26)  Média Veículo A: 21.712500,Média Veiculo B: 26.187500 por 240 periodos de tempo

Tentativa( 27)  Média Veículo A: 24.229166,Média Veiculo B: 23.791666 por 240 periodos de tempo

Tentativa( 28)  Média Veículo A: 23.129168,Média Veiculo B: 27.291666 por 240 periodos de tempo

Tentativa( 29)  Média Veículo A: 18.908333,Média Veiculo B: 25.391666 por 240 periodos de tempo

Tentativa( 30)  Média Veículo A: 23.645834,Média Veiculo B: 18.379168 por 240 periodos de tempo

Tentativa( 31)  Média Veículo A: 27.154167,Média Veiculo B: 25.779167 por 240 periodos de tempo

Tentativa( 32)  Média Veículo A: 23.379168,Média Veiculo B: 27.729166 por 240 periodos de tempo

Tentativa( 33)  Média Veículo A: 28.804167,Média Veiculo B: 25.670834 por 240 periodos de tempo

Tentativa( 34)  Média Veículo A: 24.116667,Média Veiculo B: 18.029167 por 240 periodos de tempo

Tentativa( 35)  Média Veículo A: 20.437500,Média Veiculo B: 26.504168 por 240 periodos de tempo

Tentativa( 36)  Média Veículo A: 22.183332,Média Veiculo B: 23.583334 por 240 periodos de tempo

Tentativa( 37)  Média Veículo A: 25.625000,Média Veiculo B: 23.962500 por 240 periodos de tempo

Tentativa( 38)  Média Veículo A: 21.554167,Média Veiculo B: 24.858334 por 240 periodos de tempo

Tentativa( 39)  Média Veículo A: 24.299999,Média Veiculo B: 21.875000 por 240 periodos de tempo

Tentativa( 40)  Média Veículo A: 21.020834,Média Veiculo B: 20.025000 por 240 periodos de tempo

Tentativa( 41)  Média Veículo A: 22.670834,Média Veiculo B: 22.783333 por 240 periodos de tempo

Tentativa( 42)  Média Veículo A: 24.545834,Média Veiculo B: 24.745832 por 240 periodos de tempo

Tentativa( 43)  Média Veículo A: 22.033333,Média Veiculo B: 28.170834 por 240 periodos de tempo

Tentativa( 44)  Média Veículo A: 25.437500,Média Veiculo B: 27.400000 por 240 periodos de tempo

Tentativa( 45)  Média Veículo A: 22.075001,Média Veiculo B: 25.825001 por 240 periodos de tempo

Tentativa( 46)  Média Veículo A: 24.629168,Média Veiculo B: 25.512501 por 240 periodos de tempo

Tentativa( 47)  Média Veículo A: 24.016666,Média Veiculo B: 26.195833 por 240 periodos de tempo

Tentativa( 48)  Média Veículo A: 21.587500,Média Veiculo B: 23.966667 por 240 periodos de tempo

Tentativa( 49)  Média Veículo A: 20.150000,Média Veiculo B: 22.316668 por 240 periodos de tempo

Tentativa( 50)  Média Veículo A: 20.454166,Média Veiculo B: 28.070833 por 240 periodos de tempo

Tentativa( 51)  Média Veículo A: 23.295834,Média Veiculo B: 21.325001 por 240 periodos de tempo

Tentativa( 52)  Média Veículo A: 26.891666,Média Veiculo B: 23.958334 por 240 periodos de tempo

Tentativa( 53)  Média Veículo A: 23.662500,Média Veiculo B: 26.720833 por 240 periodos de tempo

Tentativa( 54)  Média Veículo A: 22.450001,Média Veiculo B: 27.383333 por 240 periodos de tempo

Tentativa( 55)  Média Veículo A: 22.387501,Média Veiculo B: 25.825001 por 240 periodos de tempo

Tentativa( 56)  Média Veículo A: 22.770834,Média Veiculo B: 22.766666 por 240 periodos de tempo

Tentativa( 57)  Média Veículo A: 21.070833,Média Veiculo B: 21.479166 por 240 periodos de tempo

Tentativa( 58)  Média Veículo A: 31.654167,Média Veiculo B: 21.254168 por 240 periodos de tempo

Tentativa( 59)  Média Veículo A: 21.470833,Média Veiculo B: 22.341667 por 240 periodos de tempo

Tentativa( 60)  Média Veículo A: 23.658333,Média Veiculo B: 24.795834 por 240 periodos de tempo

Tentativa( 61)  Média Veículo A: 23.820833,Média Veiculo B: 24.387501 por 240 periodos de tempo

Tentativa( 62)  Média Veículo A: 24.845833,Média Veiculo B: 26.016666 por 240 periodos de tempo

Tentativa( 63)  Média Veículo A: 21.995832,Média Veiculo B: 24.620832 por 240 periodos de tempo

Tentativa( 64)  Média Veículo A: 27.083334,Média Veiculo B: 24.341667 por 240 periodos de tempo

Tentativa( 65)  Média Veículo A: 22.666666,Média Veiculo B: 24.275000 por 240 periodos de tempo

Tentativa( 66)  Média Veículo A: 20.229166,Média Veiculo B: 28.600000 por 240 periodos de tempo

Tentativa( 67)  Média Veículo A: 21.762501,Média Veiculo B: 23.637501 por 240 periodos de tempo

Tentativa( 68)  Média Veículo A: 23.254168,Média Veiculo B: 23.037500 por 240 periodos de tempo

Tentativa( 69)  Média Veículo A: 24.291666,Média Veiculo B: 26.295834 por 240 periodos de tempo

Tentativa( 70)  Média Veículo A: 23.079166,Média Veiculo B: 23.254168 por 240 periodos de tempo

Tentativa( 71)  Média Veículo A: 23.150000,Média Veiculo B: 21.900000 por 240 periodos de tempo

Tentativa( 72)  Média Veículo A: 22.441668,Média Veiculo B: 21.104166 por 240 periodos de tempo

Tentativa( 73)  Média Veículo A: 19.975000,Média Veiculo B: 22.787500 por 240 periodos de tempo

Tentativa( 74)  Média Veículo A: 20.725000,Média Veiculo B: 25.850000 por 240 periodos de tempo

Tentativa( 75)  Média Veículo A: 26.933332,Média Veiculo B: 27.845833 por 240 periodos de tempo

Tentativa( 76)  Média Veículo A: 25.291666,Média Veiculo B: 22.029167 por 240 periodos de tempo

Tentativa( 77)  Média Veículo A: 20.687500,Média Veiculo B: 22.575001 por 240 periodos de tempo

Tentativa( 78)  Média Veículo A: 25.174999,Média Veiculo B: 27.187500 por 240 periodos de tempo

Tentativa( 79)  Média Veículo A: 25.458334,Média Veiculo B: 27.383333 por 240 periodos de tempo

Tentativa( 80)  Média Veículo A: 24.575001,Média Veiculo B: 26.220833 por 240 periodos de tempo

Tentativa( 81)  Média Veículo A: 25.358334,Média Veiculo B: 22.937500 por 240 periodos de tempo

Tentativa( 82)  Média Veículo A: 31.120832,Média Veiculo B: 24.700001 por 240 periodos de tempo

Tentativa( 83)  Média Veículo A: 22.549999,Média Veiculo B: 22.629168 por 240 periodos de tempo

Tentativa( 84)  Média Veículo A: 22.049999,Média Veiculo B: 20.916666 por 240 periodos de tempo

Tentativa( 85)  Média Veículo A: 24.037500,Média Veiculo B: 23.466667 por 240 periodos de tempo

Tentativa( 86)  Média Veículo A: 21.975000,Média Veiculo B: 20.887501 por 240 periodos de tempo

Tentativa( 87)  Média Veículo A: 20.250000,Média Veiculo B: 26.283333 por 240 periodos de tempo

Tentativa( 88)  Média Veículo A: 22.454166,Média Veiculo B: 24.125000 por 240 periodos de tempo

Tentativa( 89)  Média Veículo A: 21.137501,Média Veiculo B: 21.575001 por 240 periodos de tempo

Tentativa( 90)  Média Veículo A: 20.299999,Média Veiculo B: 21.970833 por 240 periodos de tempo

Tentativa( 91)  Média Veículo A: 21.270834,Média Veiculo B: 25.650000 por 240 periodos de tempo

Tentativa( 92)  Média Veículo A: 27.833334,Média Veiculo B: 26.408333 por 240 periodos de tempo

Tentativa( 93)  Média Veículo A: 22.995832,Média Veiculo B: 25.266666 por 240 periodos de tempo

Tentativa( 94)  Média Veículo A: 23.316668,Média Veiculo B: 27.720833 por 240 periodos de tempo

Tentativa( 95)  Média Veículo A: 21.383333,Média Veiculo B: 22.687500 por 240 periodos de tempo

Tentativa( 96)  Média Veículo A: 22.700001,Média Veiculo B: 22.508333 por 240 periodos de tempo

Tentativa( 97)  Média Veículo A: 23.087500,Média Veiculo B: 24.591667 por 240 periodos de tempo

Tentativa( 98)  Média Veículo A: 21.158333,Média Veiculo B: 25.566668 por 240 periodos de tempo

Tentativa( 99)  Média Veículo A: 24.670834,Média Veiculo B: 24.804167 por 240 periodos de tempo

Tentativa( 100)  Média Veículo A: 25.466667,Média Veiculo B: 22.970833 por 240 periodos de tempo

Média Veículo A: 22.910000,Média Veiculo B: 23.820000 por 240 períodos de tempo em 100 tentativas

 

**A: Tempo Aberto = 5, B Tempo Aberto = 5**

 

Tentativa( 1)  Média Veículo A: 6.458333,Média Veiculo B: 6.645833 por 240 periodos de tempo

Tentativa( 2)  Média Veículo A: 7.816667,Média Veiculo B: 6.162500 por 240 periodos de tempo

Tentativa( 3)  Média Veículo A: 7.812500,Média Veiculo B: 8.937500 por 240 periodos de tempo

Tentativa( 4)  Média Veículo A: 8.337500,Média Veiculo B: 7.516667 por 240 periodos de tempo

Tentativa( 5)  Média Veículo A: 7.016667,Média Veiculo B: 8.612500 por 240 periodos de tempo

Tentativa( 6)  Média Veículo A: 7.679167,Média Veiculo B: 6.704167 por 240 periodos de tempo

Tentativa( 7)  Média Veículo A: 6.912500,Média Veiculo B: 7.054167 por 240 periodos de tempo

Tentativa( 8)  Média Veículo A: 5.791667,Média Veiculo B: 7.641667 por 240 periodos de tempo

Tentativa( 9)  Média Veículo A: 6.650000,Média Veiculo B: 7.545833 por 240 periodos de tempo

Tentativa( 10)  Média Veículo A: 6.470833,Média Veiculo B: 8.087500 por 240 periodos de tempo

Tentativa( 11)  Média Veículo A: 6.741667,Média Veiculo B: 7.904167 por 240 periodos de tempo

Tentativa( 12)  Média Veículo A: 9.908334,Média Veiculo B: 6.929167 por 240 periodos de tempo

Tentativa( 13)  Média Veículo A: 7.620833,Média Veiculo B: 6.437500 por 240 periodos de tempo

Tentativa( 14)  Média Veículo A: 8.191667,Média Veiculo B: 6.504167 por 240 periodos de tempo

Tentativa( 15)  Média Veículo A: 7.487500,Média Veiculo B: 7.695833 por 240 periodos de tempo

Tentativa( 16)  Média Veículo A: 6.491667,Média Veiculo B: 7.883333 por 240 periodos de tempo

Tentativa( 17)  Média Veículo A: 7.587500,Média Veiculo B: 8.570833 por 240 periodos de tempo

Tentativa( 18)  Média Veículo A: 7.358333,Média Veiculo B: 8.408334 por 240 periodos de tempo

Tentativa( 19)  Média Veículo A: 6.591667,Média Veiculo B: 6.720833 por 240 periodos de tempo

Tentativa( 20)  Média Veículo A: 6.333333,Média Veiculo B: 6.595833 por 240 periodos de tempo

Tentativa( 21)  Média Veículo A: 6.554167,Média Veiculo B: 6.937500 por 240 periodos de tempo

Tentativa( 22)  Média Veículo A: 6.383333,Média Veiculo B: 7.579167 por 240 periodos de tempo

Tentativa( 23)  Média Veículo A: 8.679167,Média Veiculo B: 7.395833 por 240 periodos de tempo

Tentativa( 24)  Média Veículo A: 6.870833,Média Veiculo B: 7.575000 por 240 periodos de tempo

Tentativa( 25)  Média Veículo A: 6.679167,Média Veiculo B: 7.683333 por 240 periodos de tempo

Tentativa( 26)  Média Veículo A: 7.754167,Média Veiculo B: 7.316667 por 240 periodos de tempo

Tentativa( 27)  Média Veículo A: 6.979167,Média Veiculo B: 6.920833 por 240 periodos de tempo

Tentativa( 28)  Média Veículo A: 6.704167,Média Veiculo B: 6.979167 por 240 periodos de tempo

Tentativa( 29)  Média Veículo A: 8.958333,Média Veiculo B: 8.179167 por 240 periodos de tempo

Tentativa( 30)  Média Veículo A: 6.575000,Média Veiculo B: 7.616667 por 240 periodos de tempo

Tentativa( 31)  Média Veículo A: 7.345833,Média Veiculo B: 5.929167 por 240 periodos de tempo

Tentativa( 32)  Média Veículo A: 6.495833,Média Veiculo B: 8.516666 por 240 periodos de tempo

Tentativa( 33)  Média Veículo A: 7.700000,Média Veiculo B: 7.620833 por 240 periodos de tempo

Tentativa( 34)  Média Veículo A: 6.783333,Média Veiculo B: 8.658334 por 240 periodos de tempo

Tentativa( 35)  Média Veículo A: 6.833333,Média Veiculo B: 7.500000 por 240 periodos de tempo

Tentativa( 36)  Média Veículo A: 8.029166,Média Veiculo B: 5.800000 por 240 periodos de tempo

Tentativa( 37)  Média Veículo A: 7.883333,Média Veiculo B: 7.370833 por 240 periodos de tempo

Tentativa( 38)  Média Veículo A: 7.479167,Média Veiculo B: 7.237500 por 240 periodos de tempo

Tentativa( 39)  Média Veículo A: 8.287500,Média Veiculo B: 6.091667 por 240 periodos de tempo

Tentativa( 40)  Média Veículo A: 8.225000,Média Veiculo B: 7.158333 por 240 periodos de tempo

Tentativa( 41)  Média Veículo A: 6.587500,Média Veiculo B: 7.458333 por 240 periodos de tempo

Tentativa( 42)  Média Veículo A: 6.083333,Média Veiculo B: 6.870833 por 240 periodos de tempo

Tentativa( 43)  Média Veículo A: 7.820833,Média Veiculo B: 6.795833 por 240 periodos de tempo

Tentativa( 44)  Média Veículo A: 10.079166,Média Veiculo B: 6.250000 por 240 periodos de tempo

Tentativa( 45)  Média Veículo A: 8.037500,Média Veiculo B: 6.162500 por 240 periodos de tempo

Tentativa( 46)  Média Veículo A: 8.254167,Média Veiculo B: 6.187500 por 240 periodos de tempo

Tentativa( 47)  Média Veículo A: 8.375000,Média Veiculo B: 7.191667 por 240 periodos de tempo

Tentativa( 48)  Média Veículo A: 6.983333,Média Veiculo B: 8.450000 por 240 periodos de tempo

Tentativa( 49)  Média Veículo A: 6.341667,Média Veiculo B: 6.812500 por 240 periodos de tempo

Tentativa( 50)  Média Veículo A: 7.008333,Média Veiculo B: 7.404167 por 240 periodos de tempo

Tentativa( 51)  Média Veículo A: 7.337500,Média Veiculo B: 5.783333 por 240 periodos de tempo

Tentativa( 52)  Média Veículo A: 6.883333,Média Veiculo B: 9.025000 por 240 periodos de tempo

Tentativa( 53)  Média Veículo A: 6.266667,Média Veiculo B: 7.916667 por 240 periodos de tempo

Tentativa( 54)  Média Veículo A: 7.095833,Média Veiculo B: 6.112500 por 240 periodos de tempo

Tentativa( 55)  Média Veículo A: 7.033333,Média Veiculo B: 7.400000 por 240 periodos de tempo

Tentativa( 56)  Média Veículo A: 8.062500,Média Veiculo B: 7.495833 por 240 periodos de tempo

Tentativa( 57)  Média Veículo A: 8.520833,Média Veiculo B: 7.608333 por 240 periodos de tempo

Tentativa( 58)  Média Veículo A: 8.208333,Média Veiculo B: 6.995833 por 240 periodos de tempo

Tentativa( 59)  Média Veículo A: 7.225000,Média Veiculo B: 10.058333 por 240 periodos de tempo

Tentativa( 60)  Média Veículo A: 6.841667,Média Veiculo B: 7.020833 por 240 periodos de tempo

Tentativa( 61)  Média Veículo A: 6.633333,Média Veiculo B: 6.170833 por 240 periodos de tempo

Tentativa( 62)  Média Veículo A: 7.050000,Média Veiculo B: 8.237500 por 240 periodos de tempo

Tentativa( 63)  Média Veículo A: 8.454166,Média Veiculo B: 6.675000 por 240 periodos de tempo

Tentativa( 64)  Média Veículo A: 6.566667,Média Veiculo B: 7.400000 por 240 periodos de tempo

Tentativa( 65)  Média Veículo A: 7.925000,Média Veiculo B: 7.683333 por 240 periodos de tempo

Tentativa( 66)  Média Veículo A: 6.679167,Média Veiculo B: 10.325000 por 240 periodos de tempo

Tentativa( 67)  Média Veículo A: 6.745833,Média Veiculo B: 8.025000 por 240 periodos de tempo

Tentativa( 68)  Média Veículo A: 7.750000,Média Veiculo B: 7.066667 por 240 periodos de tempo

Tentativa( 69)  Média Veículo A: 7.945833,Média Veiculo B: 6.558333 por 240 periodos de tempo

Tentativa( 70)  Média Veículo A: 7.566667,Média Veiculo B: 6.716667 por 240 periodos de tempo

Tentativa( 71)  Média Veículo A: 5.662500,Média Veiculo B: 6.512500 por 240 periodos de tempo

Tentativa( 72)  Média Veículo A: 7.404167,Média Veiculo B: 6.700000 por 240 periodos de tempo

Tentativa( 73)  Média Veículo A: 6.875000,Média Veiculo B: 7.091667 por 240 periodos de tempo

Tentativa( 74)  Média Veículo A: 7.216667,Média Veiculo B: 6.320833 por 240 periodos de tempo

Tentativa( 75)  Média Veículo A: 6.570833,Média Veiculo B: 7.554167 por 240 periodos de tempo

Tentativa( 76)  Média Veículo A: 7.650000,Média Veiculo B: 9.308333 por 240 periodos de tempo

Tentativa( 77)  Média Veículo A: 6.520833,Média Veiculo B: 6.129167 por 240 periodos de tempo

Tentativa( 78)  Média Veículo A: 10.600000,Média Veiculo B: 6.825000 por 240 periodos de tempo

Tentativa( 79)  Média Veículo A: 6.233333,Média Veiculo B: 7.445833 por 240 periodos de tempo

Tentativa( 80)  Média Veículo A: 7.525000,Média Veiculo B: 7.291667 por 240 periodos de tempo

Tentativa( 81)  Média Veículo A: 9.583333,Média Veiculo B: 6.804167 por 240 periodos de tempo

Tentativa( 82)  Média Veículo A: 6.745833,Média Veiculo B: 11.091666 por 240 periodos de tempo

Tentativa( 83)  Média Veículo A: 6.500000,Média Veiculo B: 9.533334 por 240 periodos de tempo

Tentativa( 84)  Média Veículo A: 8.416667,Média Veiculo B: 7.125000 por 240 periodos de tempo

Tentativa( 85)  Média Veículo A: 5.683333,Média Veiculo B: 6.295833 por 240 periodos de tempo

Tentativa( 86)  Média Veículo A: 7.658333,Média Veiculo B: 6.425000 por 240 periodos de tempo

Tentativa( 87)  Média Veículo A: 8.070833,Média Veiculo B: 6.945833 por 240 periodos de tempo

Tentativa( 88)  Média Veículo A: 8.054167,Média Veiculo B: 9.208333 por 240 periodos de tempo

Tentativa( 89)  Média Veículo A: 6.154167,Média Veiculo B: 6.400000 por 240 periodos de tempo

Tentativa( 90)  Média Veículo A: 5.841667,Média Veiculo B: 7.116667 por 240 periodos de tempo

Tentativa( 91)  Média Veículo A: 8.033334,Média Veiculo B: 6.579167 por 240 periodos de tempo

Tentativa( 92)  Média Veículo A: 8.104167,Média Veiculo B: 6.491667 por 240 periodos de tempo

Tentativa( 93)  Média Veículo A: 6.725000,Média Veiculo B: 6.900000 por 240 periodos de tempo

Tentativa( 94)  Média Veículo A: 6.408333,Média Veiculo B: 7.295833 por 240 periodos de tempo

Tentativa( 95)  Média Veículo A: 6.312500,Média Veiculo B: 7.216667 por 240 periodos de tempo

Tentativa( 96)  Média Veículo A: 6.787500,Média Veiculo B: 6.812500 por 240 periodos de tempo

Tentativa( 97)  Média Veículo A: 7.158333,Média Veiculo B: 8.187500 por 240 periodos de tempo

Tentativa( 98)  Média Veículo A: 8.062500,Média Veiculo B: 7.825000 por 240 periodos de tempo

Tentativa( 99)  Média Veículo A: 8.800000,Média Veiculo B: 7.816667 por 240 periodos de tempo

Tentativa( 100)  Média Veículo A: 9.787500,Média Veiculo B: 7.520833 por 240 periodos de tempo

Média Veículo A: 6.850000,Média Veiculo B: 6.860000 por 240 períodos de tempo em 100 tentativas

 

**A: Tempo Aberto = 15, B Tempo Aberto = 5**

 

Tentativa( 1)  Média Veículo A: 4.750000,Média Veiculo B: 73.137497 por 240 periodos de tempo

Tentativa( 2)  Média Veículo A: 4.445833,Média Veiculo B: 85.162498 por 240 periodos de tempo

Tentativa( 3)  Média Veículo A: 4.329167,Média Veiculo B: 89.129166 por 240 periodos de tempo

Tentativa( 4)  Média Veículo A: 4.545833,Média Veiculo B: 75.458336 por 240 periodos de tempo

Tentativa( 5)  Média Veículo A: 5.154167,Média Veiculo B: 76.866669 por 240 periodos de tempo

Tentativa( 6)  Média Veículo A: 4.750000,Média Veiculo B: 63.445835 por 240 periodos de tempo

Tentativa( 7)  Média Veículo A: 4.950000,Média Veiculo B: 22.087500 por 240 periodos de tempo

Tentativa( 8)  Média Veículo A: 4.787500,Média Veiculo B: 98.349998 por 240 periodos de tempo

Tentativa( 9)  Média Veículo A: 4.133333,Média Veiculo B: 65.262497 por 240 periodos de tempo

Tentativa( 10)  Média Veículo A: 4.495833,Média Veiculo B: 80.091667 por 240 periodos de tempo

Tentativa( 11)  Média Veículo A: 4.358333,Média Veiculo B: 83.316666 por 240 periodos de tempo

Tentativa( 12)  Média Veículo A: 4.337500,Média Veiculo B: 66.679169 por 240 periodos de tempo

Tentativa( 13)  Média Veículo A: 5.275000,Média Veiculo B: 78.691666 por 240 periodos de tempo

Tentativa( 14)  Média Veículo A: 4.283333,Média Veiculo B: 74.379166 por 240 periodos de tempo

Tentativa( 15)  Média Veículo A: 4.179167,Média Veiculo B: 95.808334 por 240 periodos de tempo

Tentativa( 16)  Média Veículo A: 5.345833,Média Veiculo B: 51.224998 por 240 periodos de tempo

Tentativa( 17)  Média Veículo A: 4.741667,Média Veiculo B: 51.562500 por 240 periodos de tempo

Tentativa( 18)  Média Veículo A: 4.816667,Média Veiculo B: 46.724998 por 240 periodos de tempo

Tentativa( 19)  Média Veículo A: 4.112500,Média Veiculo B: 35.716667 por 240 periodos de tempo

Tentativa( 20)  Média Veículo A: 4.616667,Média Veiculo B: 24.616667 por 240 periodos de tempo

Tentativa( 21)  Média Veículo A: 5.275000,Média Veiculo B: 52.950001 por 240 periodos de tempo

Tentativa( 22)  Média Veículo A: 4.154167,Média Veiculo B: 43.541668 por 240 periodos de tempo

Tentativa( 23)  Média Veículo A: 3.933333,Média Veiculo B: 139.979172 por 240 periodos de tempo

Tentativa( 24)  Média Veículo A: 5.012500,Média Veiculo B: 72.416664 por 240 periodos de tempo

Tentativa( 25)  Média Veículo A: 5.641667,Média Veiculo B: 34.129166 por 240 periodos de tempo

Tentativa( 26)  Média Veículo A: 5.170833,Média Veiculo B: 81.683334 por 240 periodos de tempo

Tentativa( 27)  Média Veículo A: 4.416667,Média Veiculo B: 49.954166 por 240 periodos de tempo

Tentativa( 28)  Média Veículo A: 4.137500,Média Veiculo B: 32.049999 por 240 periodos de tempo

Tentativa( 29)  Média Veículo A: 5.229167,Média Veiculo B: 50.704166 por 240 periodos de tempo

Tentativa( 30)  Média Veículo A: 4.354167,Média Veiculo B: 78.395836 por 240 periodos de tempo

Tentativa( 31)  Média Veículo A: 4.416667,Média Veiculo B: 73.625000 por 240 periodos de tempo

Tentativa( 32)  Média Veículo A: 4.225000,Média Veiculo B: 64.895836 por 240 periodos de tempo

Tentativa( 33)  Média Veículo A: 4.900000,Média Veiculo B: 53.287498 por 240 periodos de tempo

Tentativa( 34)  Média Veículo A: 5.820833,Média Veiculo B: 39.750000 por 240 periodos de tempo

Tentativa( 35)  Média Veículo A: 4.050000,Média Veiculo B: 117.220833 por 240 periodos de tempo

Tentativa( 36)  Média Veículo A: 5.270833,Média Veiculo B: 70.833336 por 240 periodos de tempo

Tentativa( 37)  Média Veículo A: 4.050000,Média Veiculo B: 46.037498 por 240 periodos de tempo

Tentativa( 38)  Média Veículo A: 5.029167,Média Veiculo B: 43.291668 por 240 periodos de tempo

Tentativa( 39)  Média Veículo A: 4.558333,Média Veiculo B: 58.295834 por 240 periodos de tempo

Tentativa( 40)  Média Veículo A: 5.120833,Média Veiculo B: 78.525002 por 240 periodos de tempo

Tentativa( 41)  Média Veículo A: 4.562500,Média Veiculo B: 46.791668 por 240 periodos de tempo

Tentativa( 42)  Média Veículo A: 4.579167,Média Veiculo B: 54.004166 por 240 periodos de tempo

Tentativa( 43)  Média Veículo A: 5.108333,Média Veiculo B: 79.112503 por 240 periodos de tempo

Tentativa( 44)  Média Veículo A: 4.837500,Média Veiculo B: 39.483334 por 240 periodos de tempo

Tentativa( 45)  Média Veículo A: 4.266667,Média Veiculo B: 57.825001 por 240 periodos de tempo

Tentativa( 46)  Média Veículo A: 4.266667,Média Veiculo B: 79.954170 por 240 periodos de tempo

Tentativa( 47)  Média Veículo A: 4.383333,Média Veiculo B: 53.404167 por 240 periodos de tempo

Tentativa( 48)  Média Veículo A: 4.558333,Média Veiculo B: 99.883331 por 240 periodos de tempo

Tentativa( 49)  Média Veículo A: 4.112500,Média Veiculo B: 77.220833 por 240 periodos de tempo

Tentativa( 50)  Média Veículo A: 4.408333,Média Veiculo B: 87.925003 por 240 periodos de tempo

Tentativa( 51)  Média Veículo A: 4.495833,Média Veiculo B: 56.587502 por 240 periodos de tempo

Tentativa( 52)  Média Veículo A: 4.587500,Média Veiculo B: 59.729168 por 240 periodos de tempo

Tentativa( 53)  Média Veículo A: 4.520833,Média Veiculo B: 99.841667 por 240 periodos de tempo

Tentativa( 54)  Média Veículo A: 4.804167,Média Veiculo B: 56.375000 por 240 periodos de tempo

Tentativa( 55)  Média Veículo A: 4.825000,Média Veiculo B: 72.987503 por 240 periodos de tempo

Tentativa( 56)  Média Veículo A: 4.758333,Média Veiculo B: 73.062500 por 240 periodos de tempo

Tentativa( 57)  Média Veículo A: 4.483333,Média Veiculo B: 63.679165 por 240 periodos de tempo

Tentativa( 58)  Média Veículo A: 4.237500,Média Veiculo B: 25.541666 por 240 periodos de tempo

Tentativa( 59)  Média Veículo A: 5.045833,Média Veiculo B: 44.049999 por 240 periodos de tempo

Tentativa( 60)  Média Veículo A: 5.654167,Média Veiculo B: 43.162498 por 240 periodos de tempo

Tentativa( 61)  Média Veículo A: 4.550000,Média Veiculo B: 78.454170 por 240 periodos de tempo

Tentativa( 62)  Média Veículo A: 4.945833,Média Veiculo B: 63.920834 por 240 periodos de tempo

Tentativa( 63)  Média Veículo A: 4.200000,Média Veiculo B: 54.104168 por 240 periodos de tempo

Tentativa( 64)  Média Veículo A: 4.162500,Média Veiculo B: 44.191666 por 240 periodos de tempo

Tentativa( 65)  Média Veículo A: 4.579167,Média Veiculo B: 47.099998 por 240 periodos de tempo

Tentativa( 66)  Média Veículo A: 4.525000,Média Veiculo B: 56.020832 por 240 periodos de tempo

Tentativa( 67)  Média Veículo A: 4.612500,Média Veiculo B: 59.212502 por 240 periodos de tempo

Tentativa( 68)  Média Veículo A: 4.454167,Média Veiculo B: 100.633331 por 240 periodos de tempo

Tentativa( 69)  Média Veículo A: 4.825000,Média Veiculo B: 44.258335 por 240 periodos de tempo

Tentativa( 70)  Média Veículo A: 3.712500,Média Veiculo B: 84.737503 por 240 periodos de tempo

Tentativa( 71)  Média Veículo A: 4.754167,Média Veiculo B: 92.724998 por 240 periodos de tempo

Tentativa( 72)  Média Veículo A: 5.012500,Média Veiculo B: 54.474998 por 240 periodos de tempo

Tentativa( 73)  Média Veículo A: 4.008333,Média Veiculo B: 82.791664 por 240 periodos de tempo

Tentativa( 74)  Média Veículo A: 4.633333,Média Veiculo B: 60.562500 por 240 periodos de tempo

Tentativa( 75)  Média Veículo A: 4.933333,Média Veiculo B: 57.529167 por 240 periodos de tempo

Tentativa( 76)  Média Veículo A: 5.187500,Média Veiculo B: 68.729164 por 240 periodos de tempo

Tentativa( 77)  Média Veículo A: 5.329167,Média Veiculo B: 48.662498 por 240 periodos de tempo

Tentativa( 78)  Média Veículo A: 4.966667,Média Veiculo B: 47.025002 por 240 periodos de tempo

Tentativa( 79)  Média Veículo A: 5.308333,Média Veiculo B: 90.441666 por 240 periodos de tempo

Tentativa( 80)  Média Veículo A: 4.737500,Média Veiculo B: 39.354168 por 240 periodos de tempo

Tentativa( 81)  Média Veículo A: 4.487500,Média Veiculo B: 60.595833 por 240 periodos de tempo

Tentativa( 82)  Média Veículo A: 4.279167,Média Veiculo B: 68.662498 por 240 periodos de tempo

Tentativa( 83)  Média Veículo A: 4.758333,Média Veiculo B: 46.654167 por 240 periodos de tempo

Tentativa( 84)  Média Veículo A: 4.616667,Média Veiculo B: 78.995834 por 240 periodos de tempo

Tentativa( 85)  Média Veículo A: 4.404167,Média Veiculo B: 35.637501 por 240 periodos de tempo

Tentativa( 86)  Média Veículo A: 4.770833,Média Veiculo B: 34.462502 por 240 periodos de tempo

Tentativa( 87)  Média Veículo A: 3.958333,Média Veiculo B: 83.191666 por 240 periodos de tempo

Tentativa( 88)  Média Veículo A: 4.191667,Média Veiculo B: 108.708336 por 240 periodos de tempo

Tentativa( 89)  Média Veículo A: 4.612500,Média Veiculo B: 50.970833 por 240 periodos de tempo

Tentativa( 90)  Média Veículo A: 5.670833,Média Veiculo B: 35.108334 por 240 periodos de tempo

Tentativa( 91)  Média Veículo A: 4.712500,Média Veiculo B: 44.974998 por 240 periodos de tempo

Tentativa( 92)  Média Veículo A: 4.762500,Média Veiculo B: 77.775002 por 240 periodos de tempo

Tentativa( 93)  Média Veículo A: 4.804167,Média Veiculo B: 63.537498 por 240 periodos de tempo

Tentativa( 94)  Média Veículo A: 4.070833,Média Veiculo B: 59.029167 por 240 periodos de tempo

Tentativa( 95)  Média Veículo A: 4.316667,Média Veiculo B: 81.758331 por 240 periodos de tempo

Tentativa( 96)  Média Veículo A: 4.695833,Média Veiculo B: 72.849998 por 240 periodos de tempo

Tentativa( 97)  Média Veículo A: 4.770833,Média Veiculo B: 79.062500 por 240 periodos de tempo

Tentativa( 98)  Média Veículo A: 4.883333,Média Veiculo B: 60.345833 por 240 periodos de tempo

Tentativa( 99)  Média Veículo A: 5.025000,Média Veiculo B: 47.854168 por 240 periodos de tempo

Tentativa( 100)  Média Veículo A: 4.666667,Média Veiculo B: 32.629166 por 240 periodos de tempo

Média Veículo A: 4.180000,Média Veiculo B: 63.369999 por 240 períodos de tempo em 100 tentativas

 

**Analisando Resultados:**

 

Foi realizado uma simulação com cada modelo desenvolvido afim de verificar qual deles apresentaria um comportamento mais satisfatório para uma possível implementação do mesmo em uma situação de trânsito real. Os dados de taxa de entrada e saída das ruas são todos aleatórios. O modelo que apresentou o melhor desempenho foi aquele que adota a política de abertura e fechamento do semáforo de acordo com o tamanho das filas das ruas A e B (modelo 1). Esta simulação dos modelos foi pensada da seguinte maneira. O período total a ser verificado foi de 240 períodos de tempo e isto representa uma tentativa de teste do modelo em questão. Foi realizado 100 tentativas de teste de cada modelo. Ou seja, foi simulado 100 vezes uma situação representada com duração de 240 períodos de tempo cada tentativa. Em relação aos outros modelos, foi constatado que o modelo com política de abertura e fechamento de maneira aleatória (modelo 2) não apresentou um resultado ruim, pois a médio de veículos presente na fila não foi elevado, mas mesmo assim o modelo 1 apresentou uma média de veículos na fila inferior. Já no modelo com tempo fixo de aberto verificou-se que se adotado um tempo fixo de aberto de 1 período de tempo para a rua A e 1 período de tempo para a rua B ele apresentou um resultado satisfatório pois foi melhor que o modelo 2 porém o modelo 1 prevalece na liderança. Já quando se amenta o período de aberto de ambas as ruas para 5 períodos de tempo, a média de veículos nas filas aumenta consideravelmente. Já no último teste do modelo 3 a rua A permanece com o semáforo aberto por 15 períodos de tempo e o semáforo da rua B por 5 períodos de tempo. Há uma discrepância entre a média de veículos nas filas. A fila A com uma média de veículos nela satisfatória, porém na fila B o resultado não foi satisfatório, pois a média de veículos na sua fila foi elevada. Este modelo 3 não respondeu muitos bem para valores maiores de tempo que os semáforos permanecerão abertos. Se ambos têm o mesmo valor de tempo aberto, mas se este tempo for mais elevado que 1 por exemplo, a tendência é que a média das filas também aumentem consideravelmente, por isso foi constatado que ele não é bom para a configuração de tempo aberto muito elevado. Ele funciona melhor com poucos períodos e se ambos as filas apresentarem o mesmo período aberto do controlador.

 

 

 