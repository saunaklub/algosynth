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

#ifndef ETUDES_ETUDESHOST
#define ETUDES_ETUDESHOST

#include <memory>
#include <vector>
#include <map>

#include <IO/OSCInput.hpp>
#include <Receivers/Receiver.hpp>

namespace SoundGenerator {

    class SoundEtude : public etudes::Receiver {
    public:
        using receivers_t =
            std::vector<std::pair<std::string, std::unique_ptr<etudes::Receiver>>>;
        
        virtual void
        registerInputs() override {};    

        SoundEtude();
        ~SoundEtude();

        void initialise();
        int outputChar(int i, int x, int t, int o);

    private:
        void initOSC();

        receivers_t receiver;
        etudes::OSCInput oscInput;

        template <typename T> bool
        dispatchValueT(std::string input, const T &value);
    };
}

#endif // ETUDES_ETUDESHOST
