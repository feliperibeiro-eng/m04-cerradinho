# Aula 01 – LED de status do rastreador

Projeto no Wokwi: https://wokwi.com/projects/477958882440199169

## 1. Contextualizar

O objetivo desta etapa é fazer o LED de status do rastreador da Cerradinho indicar que o dispositivo está ligado e funcionando. O comportamento esperado é um pulso curto de 200 ms com o LED aceso, seguido de 1800 ms apagado, formando um ciclo de 2 s que se repete enquanto o rastreador estiver energizado. O pulso curto foi escolhido para economizar energia. Considero a entrega aceita se dois critérios forem atendidos: o ciclo cronometrado no timer do simulador Wokwi fica entre 1,9 s e 2,1 s, e a corrente calculada no LED fica abaixo de 20 mA, valor recomendado pelo datasheet. Pretendo delegar à IA apenas a explicação de conceitos que ainda não domino, como o cálculo do resistor que limita a corrente do LED. A montagem do circuito, os testes no simulador, a conferência das respostas da IA com fontes primárias e as respostas da etapa Comprovar ficam comigo.

*Parágrafo redigido com apoio do Claude e revisado por mim.*

## 2. Consultar

**Pergunta feita ao Gemini:**
"Que valor de resistor limita a corrente de um LED vermelho ligado a 5 V, e de onde sai essa conta?"

**Resposta resumida:**
O Gemini indicou resistor entre 150 Ω e 220 Ω. A conta usa a Lei de Ohm descontando a queda de tensão do LED vermelho (~2 V): R = (5 V − 2 V) / 0,02 A = 150 Ω. Disse que 220 Ω é o valor comercial imediatamente acima de 150 Ω e que, com ele, a corrente cai para ~13,6 mA, aumentando a vida útil do LED.

## 3. Confrontar

**Afirmação conferida:** "150 Ω entrega a corrente máxima limite e 220 Ω é o valor comercial imediatamente acima."

- **Lei de Ohm:** I = (5 − 2) / 220 = 13,6 mA, abaixo dos 20 mA recomendados. ✔ Confirmado.
- **Datasheet do LED:** corrente recomendada de 20 mA e máximo absoluto entre 25 e 30 mA. Logo, 150 Ω (20 mA) não é o "limite máximo", e sim o valor recomendado. ⚠ Precisou de ajuste.
- **Série comercial E12:** entre 150 Ω e 220 Ω existe o 180 Ω (≈16,7 mA). ✘ A afirmação de que 220 Ω é o "imediatamente acima" está errada.
- **Animação circuito-led:** com 100 Ω: ___ mA (cálculo: 30 mA). Com 1 kΩ: ___ mA (cálculo: 3 mA).

**Conclusão:** a conta da IA está correta, mas ela confundiu corrente recomendada com corrente máxima e errou o valor comercial seguinte. Mantive 220 Ω porque deixa margem em relação aos 20 mA. Essa correção virou o ADR.

*Análise da resposta do Gemini feita com apoio do Claude e conferida por mim.*

## 4. Construir

- Projeto rodando no Wokwi: https://wokwi.com/projects/477958882440199169
- Ciclo medido no timer do simulador: ~2,0 s. Pausei a simulação em 2,080 s com o LED aceso e o pino 8 em "OUT High", dentro da janela esperada do 2º pulso (2,000–2,200 s). Critério de 1,9–2,1 s atendido. ✔
- Corrente calculada com 220 Ω: 13,6 mA (critério: abaixo de 20 mA). ✔
- Arquivos versionados nesta pasta: `sketch.ino`, `diagram.json` e captura de tela do simulador.


## 5. Comprovar

**Qual corrente passa pelo LED com 330 Ω?**
Usando a Lei de Ohm, considerando uma fonte de 5 V e um LED com queda de tensão de 2 V:
I = (5 − 2) / 330 = 3 / 330 ≈ 0,00909 A ≈ 9,1 mA.

**Por que um resistor de 0 Ω queima o LED na placa real?**
Quando a resistência diminui, a corrente aumenta. Se a resistência for zero, a corrente pode atingir um valor muito alto, limitado apenas pelas características do circuito. Isso pode ultrapassar o limite máximo absoluto de corrente indicado no datasheet do LED, causando superaquecimento e danos. Por isso, é necessário utilizar um resistor para limitar a corrente e proteger o LED.

**O que muda no código se o LED for para o pino 12?**
No arquivo `sketch.ino`, a linha `const int PINO_LED = 8;` define que o LED está conectado ao pino digital 8. Para utilizar o pino 12, é necessário alterar a linha para `const int PINO_LED = 12;`. Além disso, o fio conectado ao Arduino também deve ser transferido para o pino digital 12, mantendo o resistor em série com o LED.


## Desafio

Pisca-pisca reescrito com `millis()` no lugar de `delay()`, com padrão de dois pulsos curtos (200 ms aceso, 200 ms apagado, 200 ms aceso) seguidos de uma pausa de 1400 ms. Como o `loop()` não trava mais, o rastreador vai conseguir ler o lacre na Aula 02 enquanto o LED pisca. Código em `desafio/`.

Projeto no Wokwi: https://wokwi.com/projects/477966012765625345

*Código feito com apoio do Claude; entendi a lógica e testei no Wokwi.*

## Registro de IA

- **Gemini:** etapa Consultar (cálculo do resistor).
- **Claude:** apoio na redação do Contextualizar, na análise da resposta do Gemini, no ADR e no código do desafio.
- **ADR:** [ADR-001-resistor.md](ADR-001-resistor.md)
