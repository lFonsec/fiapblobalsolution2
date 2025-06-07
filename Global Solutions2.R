# Instalar o pacote (se necessário)
install.packages("readxl")

# Carregar o pacote
library(readxl)

library(dplyr)
# Importar o arquivo Excel
dados <- read_excel("C:/Users/lucas/Downloads/resultado.xlsx")

head(dados)


# Estatísticas descritivas
summary(dados)

dados <- dados[!(dados$vento_velocidade_m_s < 0), ]
summary(dados)

sd(dados$temperatura_do_ar)
sd(dados$umidade_relativa)
sd(dados$vento_velocidade_m_s)


