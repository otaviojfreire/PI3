

A ideia do meu projeto da disciplina de Projeto Integrador III do curso de Engenharia Eletrônica do IFSC, é algo relacionado com um grande problema encontrado em centros urbanos de nosso país e de diversos outros. Se andarmos de carro pela Avenida Beira Mar Norte em Florianópolis, podemos observar claramente o problema a ser modelado nesta disciplina. Supomos a seguinte situação na avenida citada acima, nesta avenida apresenta diversos semáforos para controle de tráfego urbano. Você se depara com uma fila de carros a sua frente e você é o último da fila. O sinal está fechado, quando ele fica verde há um tempo necessário para os motoristas reagirem e seguirem em frente. Esse tempo de reação foi algo demorado e você não conseguiu cruzar à tempo e então tem que aguardar mais um ciclo. Precisamos pensar numa otimização em situações relacionadas com sistemas de semáforos. Quando dizemos melhorar é no sentido de que há dois semáforos em um cruzamento, no semáforo A não apresenta carros na fila e no semáforo B a demanda está grande. Por que o semáforo A está aberto se não há carros na fila? A ideia do projeto é com base na teoria de filas modelar uma situação simulada para otimizar o sistema de semáforo de uma rua A e uma rua B, de acordo com a demanda de carros presentes nestas duas ruas.

A teoria das filas é uma parte da matemática estatística que estuda o comportamento de filas, desde o seu funcionamento até o processo de formação das mesmas 

![queue situation diagram](https://queue-it.com/media/5bhk3gzv/queue-situation-diagram.png)

 

Imagem retirada no website: <https://queue-it.com/blog/queuing-theory/>

 

O modelo representa uma situação que envolve a teoria das filas, ele é composto pela chegada no sistema, representado a entrada na fila, ao entrar no sistema temos a outra parte do modelo representado pela fila. O Server representa o elemento do sistema que buscamos alcançar. Imagine que este modelo representa a fila de carros um sistema de semáforos. O carro está em uma rua A e entra nesse sistema pelo Arrival(input), e então fica no seu lugar da fila formada. O semáforo representa o Server, o objetivo a ser alcançado pelos ocupantes da fila. A população de clientes é a região que engloba o sistema, incluindo a rua, fila de carros e o semáforo. A saída desse sistema é alcançada quando os carros cruzam o sinal verde e passam pelo semáforo atém cruzarem a saída(output).

 ![img](https://miro.medium.com/max/1000/1*6dpXPhWK7U9h4dGxGschxg.gif)

Gif retirado do website: <https://towardsdatascience.com/simulating-traffic-flow-in-python-ee1eab4dd20f>

 