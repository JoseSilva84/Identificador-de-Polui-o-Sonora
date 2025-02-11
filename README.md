I INTRODUÇÃO

Atualmente, o exagero da sonorização tem sido um dos elementos mais
prejudiciais a sociedade humana. Neste contexto que se observa a poluição sonora
no meio social. Seja isso via indústria, fábrica, transporte público ou até na usabilidade
indevida da voz em decibéis (dB) além do padrão, é preciso compreender que a
poluição sonora é totalmente prejudicial a saúde e harmonia de uma boa audição
humana. Segundo Estevam (p. 19), a poluição sonora no meio ambiental, após a
poluição atmosférica, é concebida pela Organização Mundial da Saúde (OMS) o
modelo mais imperante de poluição na sociedade industrializada. Segundo a
própria OMS, o ruído se torna maléfico caso for superior a 75 dB Portanto, recomenda
não passar de 65 dB durante o dia e orienta que durante a noite não ultrapasse a 30
dB. Daí, percebe-se a real necessidade de produzir sistemas embarcados em prol do
controle do nível de decibéis no ambiente local, em especial, no lar a fim de gerenciar
de maneira mais saudável e positiva a qualidade sonora na esfera familiar.
Diante do exposto mencionado acima, este trabalho apresenta um projeto cujo
objetivo é sinalizar via som e led, quando os decibéis do ambiente ultrapassar o a
sonorização permitida. O desenvolvimento dele se dar por meio de um código cujo
microcontrolador utiliza a linguagem C e as bibliotecas “pico/stdlib.h”, “pico/stdlib.h” e
“hardware/adc.h” com o objetivo de realizar a leitura dos valores do microfone – este
é ligado no pino GPIO como entrada e os valores são disponibilizados no console.

II OBJETIVOS

O objetivo deste projeto é disponibilizar um sistema de monitoramento do som
no ambiente casa por meio do microcontrolador Raspberry Pi Pico (RP2040) e de um
microfone embutido na placa. dessa forma, o sistema coletará os dados ambientais e
os exibirá no console a cada 1 segundo, realizando, nesses moldes, a análise das
condições sonoras em tempo real.

III JUSTIFICATIVA

A importância da gerência da sonorização no ambiente familiar é relevante
para a construção e educação de uma melhor saúde auditiva nos moldes da OMS.
Até porque, atualmente, a poluição sonora além de ser prejudicial a saúde também
fere o direito de liberdade da comunidade vizinha, uma vez que que tal poluição
interfere na qualidade sonora dos demais vizinhos, ademais, numa melhor qualidade
de diálogo e entretenimento caseiros.
O sistema foi elaborado no microcotrolador da Raspberry Pi Pico (RP2040) por
ser ideal e de fácil desenvolvimento. O sensor de som, o microfone, realiza a busca
sonora no ambiente em tempo real, apresentando-a no console o resultado – caso o
número de decibéis for abaixo de 75 dB, será printado no console: “o som ambiente
está bom” e permanece a luz verde, mas se os decibéis forem maiores a 75 dB, será
printado no console: “o som ambiente é prejudicial” e acenderá a luz vermelha.
