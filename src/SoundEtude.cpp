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

#include <iostream>
#include <iomanip>

#include "SoundEtude.hpp"

namespace SoundGenerator {
    SoundEtude::SoundEtude() {
            registerInputs();
        }

    void SoundEtude::registerInputs(){
        registerInput("/octave", vec_int_t{1});
    }

    int SoundEtude::saw (int freq) {
        auto octave =  getValue<int>("/octave");
        return freq * octave;
    }

    int SoundEtude::outputChar(int i,int x, int t, int o){
        return( 
                (3&x&( i * ( ( 3 & i >> 16 ? "BY}6YB6%" : "Qj}6jQ6%" ) [t%8] + 51) >> o)
                ) << 4 );
    };
}
