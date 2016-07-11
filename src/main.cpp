/*

  Études Audiovisuel - Graphical elements for audiovisual composition.
  Copyright (C) 2015-2016 Patric Schmitz

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <cstdio>
#include<iostream>
#include <IO/OSCInput.hpp>
#include <SoundEtude.hpp>

int main(){
    
    SoundGenerator::SoundEtude sound;

    etudes::OSCInput oscInput(6667);
    oscInput.start();


    for(int i = 0;; ++i) {
        //std::cout << (char)sound.outputChar(i , 1, i >> 14, 12);
        std::cout << (char) sound.saw(i * 4);
        std::cout.flush();
    }

    return 0;
}
