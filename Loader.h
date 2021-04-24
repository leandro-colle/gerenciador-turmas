#pragma once

#ifndef __LOADER_H_INCLUDED__
#define __LOADER_H_INCLUDED__

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <thread>
#include <chrono>

#include "Helpers/IO.cpp"
#include "Helpers/MediaAritmetica.cpp"

#include "Interfaces/IPessoa.cpp"
#include "Interfaces/IDesempenho.cpp"
#include "Interfaces/IMain.cpp"
#include "Interfaces/ITurma.cpp"

#include "Entities/Curso.cpp"
#include "Entities/Pessoa.cpp"
#include "Entities/Desempenho.cpp"
#include "Entities/Aluno.cpp"
#include "Entities/Professor.cpp"
#include "Entities/Turma.cpp"

#include "Iterators/AlunoIterator.cpp"
#include "Iterators/TurmaIterator.cpp"

#include "Main.cpp"

#endif