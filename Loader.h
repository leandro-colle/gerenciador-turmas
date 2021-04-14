#pragma once

#ifndef __LOADER_H_INCLUDED__
#define __LOADER_H_INCLUDED__

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <thread>
#include <chrono>

#include "Interfaces/IPessoa.cpp"
#include "Interfaces/IDesempenho.cpp"
#include "Interfaces/IMain.cpp"
#include "Interfaces/ITurma.cpp"

#include "Classes/Pessoa.cpp"
#include "Classes/MediaAritmetica.cpp"
#include "Classes/Desempenho.cpp"
#include "Classes/Curso.cpp"
#include "Classes/Aluno.cpp"
#include "Classes/AlunoIterator.cpp"
#include "Classes/Professor.cpp"
#include "Classes/Turma.cpp"
#include "Classes/TurmaIterator.cpp"
#include "Classes/IO.cpp"
#include "Classes/Main.cpp"

#endif