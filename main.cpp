/*

Autor(es):
  Luís Augusto Simas do Nascimento - 790828
  Pedro Klesse - 790746
  Luana de Queiroz Garcia - 740953
Data de Criação: 14/06/2021
Data de Atualização: 14/06/2021

Objetivos: Trabalho de AED1

*/

// Bibliotecas
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <string>
#include <time.h>

#include "listacadastral/lista.cpp"
#include "listacadastral/lista.h"
#include "livro/livro.h"
#include "pilha/pilha.cpp"
#include "pilha/pilha.h"

#include "button/button.h"

using namespace std;

// Função principal
int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "Portuguese");

  // Lista pra cada categoria
  Lista<Livro> lista_letras("Letras");
  Lista<Livro> lista_filosofia("Filosofia");
  Lista<Livro> lista_geografia("Geografia");
  Lista<Livro> lista_historia("História");
  Lista<Livro> lista_matematica("Matemática");
  Lista<Livro> lista_psicologia("Psicologia");
  Lista<Livro> lista_informatica("Informática");
  Lista<Livro> lista_quimica("Química");
  Lista<Livro> lista_arte("Arte");

  // Vetor que armazena todas as listas(estantes)
  Lista<Livro> listas[9] = {
      lista_letras,      lista_filosofia,  lista_geografia,
      lista_historia,    lista_matematica, lista_psicologia,
      lista_informatica, lista_quimica,    lista_arte};

  Livro letras_l1(L"Libras: conhecimento além dos sinais", L"Maria Cristina da Cunha", L"Letras", 2011, L"Pearson");
  Livro letras_l2(L"Comunicação e linguagem", L"Thelma de Carvalho Guimarães", L"Letras", 2012, L"Pearson");
  Livro letras_l3(L"Teoria da Literatura I", L"Pedro Paulo da Silva", L"Letras", 2009, L"Pearson");
  Livro letras_l4(L"Língua latina", L"Charlene Martins Miotti", L"Letras", 2010, L"Pearson");
  Livro filosofia_l5(L"Introdução à Filosofia", L"João Mattar", L"Filosofia", 2010, L"Pearson");
  Livro filosofia_l6(L"Ética", L"Maria Thereza Pompa Antunes", L"Filosofia", 2012, L"Pearson");
  Livro filosofia_l7(L"Correntes modernas de filosofia", L"José Ferraz Neto", L"Filosofia", 2013, L"Pearson");
  Livro filosofia_l8(L"Genealogia da Moral", L"Friedrich Nietzsche", L"Filosofia", 1887, L"Vozes");
  Livro geografia_l9(L"Hidrologia", L"Diego Barreto de Oliveira", L"Geografia", 2015, L"Pearson");
  Livro geografia_l10(L"Espaço Geográfico: ensino e representação", L"Rosangela Doin de Almeida", L"Geografia", 1989, L"Contexto");
  Livro geografia_l11(L"Pensamento geográfico brasileiro", L"Ruy Moreira", L"Geografia", 2008, L"Contexto");
  Livro geografia_l12(L"Globalização e espaço geográfico", L"Eustáquio de Sene", L"Geografia", 2004, L"Contexto");
  Livro historia_l13(L"No Tempo das Especiarias: o império da pimenta e do açúcar", L"Fábio Pestana", L"História", 2006, L"Contexto");
  Livro historia_l14(L"Dicionário de Datas da História do Brasil", L"Circe Bittencour", L"História", 2007, L"Contexto");
  Livro historia_l15(L"História do Café", L"Ana Luiza Martins", L"História", 2008, L"Contexto");
  Livro historia_l16(L"As Primeiras Civilizações", L"Jaime Pinsky", L"História", 2011, L"Contexto");
  Livro matematica_l17(L"Geometria Analítica: Um Tratamento Vetorial", L"Ivan de Camargo", L"Matemática", 2005, L"Pearson");
  Livro matematica_l18(L"Matemática financeira", L"André Wakamatsu", L"Matemática", 2018, L"Pearson");
  Livro matematica_l19(L"Métodos numéricos em equações diferenciais", L"Marina Vargas", L"Matemática", 2021, L"Intersaberes");
  Livro matematica_l20(L"Geometrias Não Euclidianas", L"Nelson Pereira", L"Matemática", 2020, L"Intersaberes");
  Livro psicologia_l21(L"Teorias da Personalidade: da teoria clássica à pesquisa moderna", L"Howard S. Friedman", L"Psicologia", 2003, L"Pearson");
  Livro psicologia_l22(L"Introdução à Psicologia", L"Charles G. Morris", L"Psicologia", 2004, L"Pearson");
  Livro psicologia_l23(L"A Psicanálise nas Tramas da Cidade", L"Bernardo Tanis", L"Psicologia", 2009, L"Pearson");
  Livro psicologia_l24(L"Burnout: quando o trabalho ameaça o bem-estar do trabalhador", L"Ana Maria Benevides Pereira", L"Psicologia", 2014, L"Pearson");
  Livro informatica_l25(L"Aprenda Programação Orientada a Objetos em 21 dias", L"Anthony Sintes", L"Informática", 2002, L"Pearson");
  Livro informatica_l26(L"Treinamento em Linguagem C++: módulo 1", L"Victorine Viviane Mizrahi", L"Informática", 1996, L"Pearson");
  Livro informatica_l27(L"Manual Completo do Linux: guia do administrador", L"Evi Nemeth", L"Informática", 2004, L"Pearson");
  Livro informatica_l28(L"Compiladores: princípios, técnicas e ferramentas", L"Alfred V. Alho", L"Informática", 2007, L"Pearson");
  Livro quimica_l29(L"Química Orgânica", L"Bianca Sandrino", L"Química", 2020, L"Intersaberes");
  Livro quimica_l30(L"Química Quântica: Origens e Aplicações", L"Liziane Barbara Bugalski", L"Química", 2019, L"Intersaberes");
  Livro quimica_l31(L"Manual de Ar Comprimido e Gases", L"John P. Rollins", L"Química", 2003, L"Pearson");
  Livro quimica_l32(L"Estudos de eletroquímica: reações químicas e energia", L"Ana Luiza Lorenzen", L"Química", 2017, L"Intersaberes");
  Livro arte_l33(L"Estética e história da arte", L"Humberta Gomes Machado Porto", L"Arte", 2016, L"Pearson");
  Livro arte_l34(L"História do cinema mundial", L"Fernando Mascarello", L"Arte", 2014, L"Papirus");
  Livro arte_l35(L"Beethoven: as muitas faces de um gênio", L"João Mauricio Galindo", L"Arte", 2019, L"Contexto");
  Livro arte_l36(L"O cinema de Quentin Tarantino", L"Mauro Baptista", L"Arte", 2018, L"Papirus");

  Livro lista_fixa[] = {
      letras_l1,       letras_l2,       letras_l3,
      letras_l4,       filosofia_l5,    filosofia_l6,
      filosofia_l7,    filosofia_l8,    geografia_l9,
      geografia_l10,   geografia_l11,   geografia_l12,
      historia_l13,    historia_l14,    historia_l15,
      historia_l16,    matematica_l17,  matematica_l18,
      matematica_l19,  matematica_l20,  psicologia_l21,
      psicologia_l22,  psicologia_l23,  psicologia_l24,
      informatica_l25, informatica_l26, informatica_l27,
      informatica_l28, quimica_l29,     quimica_l30,
      quimica_l31,     quimica_l32,     arte_l33,
      arte_l34,        arte_l35,        arte_l36}; // Pilha com os livros

  Pilha<Livro> pilha(10, lista_fixa);

  sf::RenderWindow window(sf::VideoMode(626 * 2, 375 * 2),
                          "Bibliotecária Leila");
  sf::Texture bgTexture;
  sf::Texture girlTexture;
  sf::Texture dialogoTexture;
  // sf::Texture botaoHistoriaTexture;
  // sf::Texture botaoPsicologiaTexture;
  // sf::Texture botaoLetrasTexture;
  // sf::Texture botaoFilosofiaTexture;
  // sf::Texture botaoGeografiaTexture;
  // sf::Texture botaoMatematicaTexture;
  // sf::Texture botaoInformaticaTexture;
  // sf::Texture botaoQuimicaTexture;
  // sf::Texture botaoArteTexture;
  // sf::Texture botaoHistoriaClicadoTexture;
  // sf::Texture botaoPsicologiaClicadoTexture;
  // sf::Texture botaoLetrasClicadoTexture;
  // sf::Texture botaoFilosofiaClicadoTexture;
  // sf::Texture botaoGeografiaClicadoTexture;
  // sf::Texture botaoMatematicaClicadoTexture;
  // sf::Texture botaoInformaticaClicadoTexture;
  // sf::Texture botaoQuimicaClicadoTexture;
  // sf::Texture botaoArteClicadoTexture;
  sf::Sprite background;
  sf::Sprite girl;
  sf::Sprite dialogo;
  // sf::Sprite botao_historia;
  // sf::Sprite botao_psicologia;
  // sf::Sprite botao_letras;
  // sf::Sprite botao_filosofia;
  // sf::Sprite botao_geografia;
  // sf::Sprite botao_matematica;
  // sf::Sprite botao_informatica;
  // sf::Sprite botao_quimica;
  // sf::Sprite botao_arte;
  // sf::Sprite botao_historia_clicado;
  // sf::Sprite botao_psicologia_clicado;
  // sf::Sprite botao_letras_clicado;
  // sf::Sprite botao_filosofia_clicado;
  // sf::Sprite botao_geografia_clicado;
  // sf::Sprite botao_matematica_clicado;
  // sf::Sprite botao_informatica_clicado;
  // sf::Sprite botao_quimica_clicado;
  // sf::Sprite botao_arte_clicado;

  if (!bgTexture.loadFromFile("./interface/assets/imagens/background.jpg")) {
    cout << "Erro: não foi possível carregar a imagem de background" << endl;
  } else {
    // resized background
    sf::Vector2u TextureSize = bgTexture.getSize(); // Get size of texture.
    sf::Vector2u WindowSize = window.getSize();     // Get size of window.

    float ScaleX = (float)WindowSize.x / TextureSize.x;
    float ScaleY = (float)WindowSize.y / TextureSize.y; // Calculate scale.

    background.setScale(ScaleX, ScaleY); // Set scale.
    background.setTexture(bgTexture, true);
  }

  if (!girlTexture.loadFromFile("./interface/assets/imagens/bibliotecaria.png")) {
    cout << "Erro: não foi possível carregar a imagem da bela moça" << endl;
  } else {
    girl.setTexture(girlTexture);
    girl.setPosition(0, window.getSize().y - girl.getGlobalBounds().height);
  }

  if (!dialogoTexture.loadFromFile("./interface/assets/imagens/dialogo.png")) {
    cout << "Erro: não foi possível carregar a imagem do dialogo" << endl;
  } else {
    dialogo.setTexture(dialogoTexture);
    dialogo.setPosition(girl.getGlobalBounds().width - 150,
                        (window.getSize().y - dialogo.getGlobalBounds().height -
                         girl.getGlobalBounds().height));
  }

  sf::Font font;
  sf::Text text;

  if (!font.loadFromFile("./interface/assets/fonts/Roboto-Bold.ttf")) {
    cout << "Erro: não foi possível carregar a fonte";
  } else {
    Livro livro = pilha.remover();
    text.setFont(font);
    text.setString(
      L"Hmmm, temos aqui o\n" +
      livro.getNome() +
      L"\n escrito por " +
      livro.getAutor() +
      L"\n em " +
      to_wstring(livro.getAnoLancamento())
    );
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(dialogo.getPosition().x + 150, dialogo.getPosition().y + 70);
  }

  // Loading interface buttons
  Button botao_historia("historia");
  Button botao_psicologia("psicologia");
  Button botao_letras("letras");
  Button botao_filosofia("filosofia");
  Button botao_geografia("geografia");
  Button botao_matematica("matematica");
  Button botao_informatica("informatica");
  Button botao_quimica("quimica");
  Button botao_arte("artes");

  // Posicionando os botoes
  botao_historia.setPosition(440, 600);
  botao_psicologia.setPosition(600, 600);
  botao_letras.setPosition(770, 600);
  botao_filosofia.setPosition(920, 600);
  botao_geografia.setPosition(320, botao_historia.getPosition().y + 65);
  botao_matematica.setPosition(510, botao_historia.getPosition().y + 65);
  botao_informatica.setPosition(685, botao_historia.getPosition().y + 65);
  botao_quimica.setPosition(840, botao_historia.getPosition().y + 65);
  botao_arte.setPosition(1010, botao_historia.getPosition().y + 65);

  // //botao historia
  // if(!botaoHistoriaTexture.loadFromFile("./interface/assets/imagens/botoes/botoes_historia.png")
  // || !botaoHistoriaClicadoTexture.loadFromFile("./interface/assets/imagens/botoes_clicados/botoes_clicados_historia.png")){
  //   cout << "Erro: não foi possível carregar a imagem do botão história" << endl;
  // }else{
  //   botao_historia.setTexture(botaoHistoriaTexture);
  //   botao_historia.setPosition(440, 600);

  //   botao_historia_clicado.setTexture(botaoHistoriaClicadoTexture);
  //   botao_historia_clicado.setPosition(440, 600);
  // }

  // //botao psicologia
  // if(!botaoPsicologiaTexture.loadFromFile("./interface/assets/imagens/botoes/botoes_psicologia.png")
  // || !botaoPsicologiaClicadoTexture.loadFromFile("./interface/assets/imagens/botoes_clicados/botoes_clicados_psicologia.png")){
  //   cout << "Erro: não foi possível carregar a imagem do botão psicologia" << endl;
  // }else{
  //   botao_psicologia.setTexture(botaoPsicologiaTexture);
  //   botao_psicologia.setPosition(600, 600);

  //   botao_psicologia_clicado.setTexture(botaoPsicologiaClicadoTexture);
  //   botao_psicologia_clicado.setPosition(600, 600);
  // }

  // //botao letras
  // if(!botaoLetrasTexture.loadFromFile("./interface/assets/imagens/botoes/botoes_letras.png")
  // || !botaoLetrasClicadoTexture.loadFromFile("./interface/assets/imagens/botoes_clicados/botoes_clicados_letras.png")){
  //   cout << "Erro: não foi possível carregar a imagem do botão letras" << endl;
  // }else{
  //   botao_letras.setTexture(botaoLetrasTexture);
  //   botao_letras.setPosition(770, 600);

  //   botao_letras_clicado.setTexture(botaoLetrasClicadoTexture);
  //   botao_letras_clicado.setPosition(770, 600);
  // }

  // //botao filosofia
  // if(!botaoFilosofiaTexture.loadFromFile("./interface/assets/imagens/botoes/botoes_filosofia.png")
  // || !botaoFilosofiaClicadoTexture.loadFromFile("./interface/assets/imagens/botoes_clicados/botoes_clicados_filosofia.png")){
  //   cout << "Erro: não foi possível carregar a imagem do botão filosofia" << endl;
  // }else{
  //   botao_filosofia.setTexture(botaoFilosofiaTexture);
  //   botao_filosofia.setPosition(920, 600);

  //   botao_filosofia_clicado.setTexture(botaoFilosofiaClicadoTexture);
  //   botao_filosofia_clicado.setPosition(920, 600);
  // }

  // //botao geografia
  // if(!botaoGeografiaTexture.loadFromFile("./interface/assets/imagens/botoes/botoes_geografia.png")
  // || !botaoGeografiaClicadoTexture.loadFromFile("./interface/assets/imagens/botoes_clicados/botoes_clicados_geografia.png")){
  //   cout << "Erro: não foi possível carregar a imagem do botão geografia" << endl;
  // }else{
  //   botao_geografia.setTexture(botaoGeografiaTexture);
  //   botao_geografia.setPosition(350, botao_historia.getPosition().y + 65);

  //   botao_geografia_clicado.setTexture(botaoGeografiaClicadoTexture);
  //   botao_geografia_clicado.setPosition(350, botao_historia.getPosition().y + 65);
  // }

  // //botao matematica
  // if(!botaoMatematicaTexture.loadFromFile("./interface/assets/imagens/botoes/botoes_matematica.png")
  // || !botaoMatematicaClicadoTexture.loadFromFile("./interface/assets/imagens/botoes_clicados/botoes_clicados_matematica.png")){
  //   cout << "Erro: não foi possível carregar a imagem do botão matematica" << endl;
  // }else{
  //   botao_matematica.setTexture(botaoMatematicaTexture);
  //   botao_matematica.setPosition(510, botao_historia.getPosition().y + 65);

  //   botao_matematica_clicado.setTexture(botaoMatematicaClicadoTexture);
  //   botao_matematica_clicado.setPosition(510, botao_historia.getPosition().y + 65);
  // }

  // //botao quimica
  // if(!botaoQuimicaTexture.loadFromFile("./interface/assets/imagens/botoes/botoes_quimica.png")
  // || !botaoQuimicaClicadoTexture.loadFromFile("./interface/assets/imagens/botoes_clicados/botoes_clicados_quimica.png")){
  //   cout << "Erro: não foi possível carregar a imagem do botão quimica" << endl;
  // }else{
  //   botao_quimica.setTexture(botaoQuimicaTexture);
  //   botao_quimica.setPosition(685, botao_historia.getPosition().y + 65);

  //   botao_quimica_clicado.setTexture(botaoQuimicaClicadoTexture);
  //   botao_quimica_clicado.setPosition(685, botao_historia.getPosition().y + 65);
  // }

  // //botao informatica
  // if(!botaoInformaticaTexture.loadFromFile("./interface/assets/imagens/botoes/botoes_informatica.png")
  // || !botaoInformaticaClicadoTexture.loadFromFile("./interface/assets/imagens/botoes_clicados/botoes_clicados_informatica.png")){
  //   cout << "Erro: não foi possível carregar a imagem do botão informatica" << endl;
  // }else{
  //   botao_informatica.setTexture(botaoInformaticaTexture);
  //   botao_informatica.setPosition(840, botao_historia.getPosition().y + 65);

  //   botao_informatica_clicado.setTexture(botaoInformaticaClicadoTexture);
  //   botao_informatica_clicado.setPosition(840, botao_historia.getPosition().y + 65);
  // }

  // //botao arte
  // if(!botaoArteTexture.loadFromFile("./interface/assets/imagens/botoes/botoes_artes.png")
  // || !botaoArteClicadoTexture.loadFromFile("./interface/assets/imagens/botoes_clicados/botoes_clicados_artes.png")){
  //   cout << "Erro: não foi possível carregar a imagem do botão arte" << endl;
  // }else{
  //   botao_arte.setTexture(botaoArteTexture);
  //   botao_arte.setPosition(1010, botao_historia.getPosition().y + 65);

  //   botao_arte_clicado.setTexture(botaoArteClicadoTexture);
  //   botao_arte_clicado.setPosition(1010, botao_historia.getPosition().y + 65);
  // }

  while (window.isOpen()) {
    sf::Event event;
    Button buttonPressed;

    // While there are pending events
    while (window.pollEvent(event)) {
      // Check the element type
      switch (event.type) {
      // sf::Event::Closed is triggered whenever the user wants to close
      // the window via any method provided by the window manager
      case sf::Event::Closed:
        window.close();
        break;
      case sf::Event::MouseButtonPressed:
        if (event.mouseButton.button == 0){
          botao_historia.click(sf::Mouse::getPosition(window));
          botao_psicologia.click(sf::Mouse::getPosition(window));
          botao_letras.click(sf::Mouse::getPosition(window));
          botao_filosofia.click(sf::Mouse::getPosition(window));
          botao_geografia.click(sf::Mouse::getPosition(window));
          botao_matematica.click(sf::Mouse::getPosition(window));
          botao_informatica.click(sf::Mouse::getPosition(window));
          botao_quimica.click(sf::Mouse::getPosition(window));
          botao_arte.click(sf::Mouse::getPosition(window));
        }
        break;
      case sf::Event::MouseButtonReleased:
          botao_historia.release(sf::Mouse::getPosition(window));
          botao_psicologia.release(sf::Mouse::getPosition(window));
          botao_letras.release(sf::Mouse::getPosition(window));
          botao_filosofia.release(sf::Mouse::getPosition(window));
          botao_geografia.release(sf::Mouse::getPosition(window));
          botao_matematica.release(sf::Mouse::getPosition(window));
          botao_informatica.release(sf::Mouse::getPosition(window));
          botao_quimica.release(sf::Mouse::getPosition(window));
          botao_arte.release(sf::Mouse::getPosition(window));
        break;
      default:
        break;
      }
    }

    window.clear();
    window.draw(background);
    window.draw(girl);
    window.draw(dialogo);
    window.draw(text);
    window.draw(botao_historia);
    window.draw(botao_psicologia);
    window.draw(botao_letras);
    window.draw(botao_filosofia);
    window.draw(botao_geografia);
    window.draw(botao_matematica);
    window.draw(botao_informatica);
    window.draw(botao_quimica);
    window.draw(botao_arte);
    window.display();
  }

  return 0;
}
