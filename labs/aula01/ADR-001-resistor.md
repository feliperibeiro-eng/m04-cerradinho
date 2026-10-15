# ADR 001 – Valor comercial do resistor do LED de status

**Status:** Aceito
**Data:** 15/10/2026
**Contexto da IA:** Gemini, etapa Consultar da Aula 01

## Contexto
O LED de status (vermelho, pino 8, alimentação de 5 V) precisa de um resistor que limite a corrente abaixo dos 20 mA recomendados pelo datasheet. Consultei o Gemini sobre o valor e a origem da conta.

## Sugestão da IA
O Gemini calculou corretamente R = (5 V − 2 V) / 0,02 A = 150 Ω, mas afirmou que:
1. 150 Ω entrega a "corrente máxima limite" do LED;
2. 220 Ω é o valor comercial "imediatamente acima" de 150 Ω.

## O que foi corrigido
1. **Corrente máxima x recomendada:** pelo datasheet, 20 mA é a corrente recomendada; o máximo absoluto fica entre 25 e 30 mA. A IA confundiu os dois conceitos.
2. **Série comercial:** na série E12 (100, 120, 150, 180, 220 Ω...), o valor imediatamente acima de 150 Ω é **180 Ω** (≈16,7 mA), não 220 Ω.

## Decisão
Mantive **220 Ω** (≈13,6 mA). É um valor comercial comum, fica bem abaixo dos 20 mA recomendados e dá margem para variação na queda de tensão do LED. A escolha é intencional por margem de segurança, e não porque 220 Ω seria o "próximo valor".

## Consequências
- Corrente de ~13,6 mA, dentro do critério de aceitação (< 20 mA).
- Brilho um pouco menor que com 150 Ω ou 180 Ω, aceitável para um LED de status.
- Lição: conferir afirmações da IA sobre valores normalizados contra a tabela da série E12, e não aceitar o "próximo valor" sem checar.

*Redigido com apoio do Claude e revisado por mim.*
