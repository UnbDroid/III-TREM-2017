/*
Código principal Bob o Trem vai ao Sítio
*/
//ESQUELETO DO CODIGO
    //Atuadores
        //Movimento
          // void frente(void);
          // void tras(void);
          // void giraEsquerdaDireita(int direcao);
          // void para();
        //
        // //FUNÇÕES SELETOR

        // //FUNÇÕES CREMALHEIRA

        // //FUNÇÕES GARRA

        // //FUNÇÕES PORTATRASEIRA

        //
    //Sensoriamento
        // void temBoneco();
        // void corChao();
        // void usFrente();
        // void usLateral();
        // void corBoneco(); //TESTES COM TC320
        //
        // //Percorrimento
        // int distPercorrida();// NECESSITA TESTES COM MEDIDAS DO ROBO
    //FILTROS

//CONSTANTES

#define DISTAREARESGATE 300 - 30
#define VAZIO

//VARIAVEIS

void VaiProSitioMeuFilho(){
  int tempAtual = millis();

  if(distPercorrida() < DISTAREARESGATE){

  }
  else if(temBoneco()){
    //ESVAZIA o espaço, leva todos os bonecos pra direita ou esquerda
    //VOLTA para o centro e virado em direção a Leia e Darth Vader
  }
  else if(corChao()){
    //ALINHA
  }
  else if(usFrente() < VAZIO){
    //PEGA OS DOIS BONECOS
    //ATIVA: Garra, Cremalheira, Garra, Seletor
    //VOLTA AO NORMAL
  }
  else if(usLateral(DIREITA)){
    //CORRIGE COM AS LEITURAS + ENCODER
  }
  else if(usLateral(ESQUERDA)){
    //CORRIGE COM AS LEITURAS + ENCODER
  }


}


void init();// inicia todas as portas
void setup(){}
void loop(){}
