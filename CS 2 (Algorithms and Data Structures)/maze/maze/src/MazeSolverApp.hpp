/**
 * @file MazeSolverApp.hpp
 * @author Ellen Price <<eprice@caltech.edu>>
 * @version 1.0
 * @date 2014-2015
 * @copyright see License section
 *
 * @brief Definitions for main application class.
 *
 * @section License
 * Copyright (c) 2014-2015 California Institute of Technology.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above
 *   copyright notice, this list of conditions and the following disclaimer
 *   in the documentation and/or other materials provided with the
 *   distribution.
 * * Neither the name of the  nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are those
 * of the authors and should not be interpreted as representing official policies,
 * either expressed or implied, of the California Institute of Technology.
 *
 */

#ifndef __MAZESOLVERAPP_H__
#define __MAZESOLVERAPP_H__

#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <iostream>
#include "RecursiveBacktracker.hpp"
#include "MazeGrid.hpp"
#include "MazeSolverBase.hpp"
#include "DepthFirstSolver.hpp"
#include "BreadthFirstSolver.hpp"

#define SCREEN_WIDTH    (800)
#define SCREEN_HEIGHT   (600)

#define MAZE_H_LENGTH   (10)
#define MAZE_V_LENGTH   (20)

#define MAZE_X_OFFSET   (42)
#define MAZE_Y_OFFSET   (30)

#define PATH_X_OFFSET   (52)
#define PATH_Y_OFFSET   (40)

/**
 * @brief Main application class with SDL handlers, etc.
 */
class MazeSolverApp
{
public:
    MazeSolverApp();
    ~MazeSolverApp();

    bool OnInit();
    int OnExecute();
    void OnEvent(SDL_Event *event);
    void OnRender();
    void OnCleanup();

private:
    bool running;
    SDL_Surface *surf;

    RecursiveBacktracker *rb;
    MazeGrid *maze;
    MazeSolverBase *solver;
    void draw_maze();
    void draw_path();
};

#endif
