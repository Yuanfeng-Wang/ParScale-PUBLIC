/*------------------------------------------------------------------------------------*\

                                      /$$$$$$                      /$$
                                     /$$__  $$                    | $$
        /$$$$$$   /$$$$$$   /$$$$$$ | $$  \__/  /$$$$$$$  /$$$$$$ | $$  /$$$$$$
       /$$__  $$ |____  $$ /$$__  $$|  $$$$$$  /$$_____/ |____  $$| $$ /$$__  $$
      | $$  \ $$  /$$$$$$$| $$  \__/ \____  $$| $$        /$$$$$$$| $$| $$$$$$$$
      | $$  | $$ /$$__  $$| $$       /$$  \ $$| $$       /$$__  $$| $$| $$_____/
      | $$$$$$$/|  $$$$$$$| $$      |  $$$$$$/|  $$$$$$$|  $$$$$$$| $$|  $$$$$$$
      | $$____/  \_______/|__/       \______/  \_______/ \_______/|__/ \_______/
      | $$
      | $$
      |__/        A Compilation of Particle Scale Models

   Copyright (C): 2014 DCS Computing GmbH (www.dcs-computing.com), Linz, Austria
                  2014 Graz University of Technology (ippt.tugraz.at), Graz, Austria
---------------------------------------------------------------------------------------
License
    ParScale is licensed under the GNU LESSER GENERAL PUBLIC LICENSE (LGPL).

    Everyone is permitted to copy and distribute verbatim copies of this license
    document, but changing it is not allowed.

    This version of the GNU Lesser General Public License incorporates the terms
    and conditions of version 3 of the GNU General Public License, supplemented
    by the additional permissions listed below.

    You should have received a copy of the GNU Lesser General Public License
    along with ParScale. If not, see <http://www.gnu.org/licenses/lgpl.html>.

    This code is designed to simulate transport processes (e.g., for heat and
    mass) within porous and no-porous particles, eventually undergoing
    chemical reactions.

    Parts of the code were developed in the frame of the NanoSim project funded
    by the European Commission through FP7 Grant agreement no. 604656.
\*-----------------------------------------------------------------------------------*/

#ifndef PASC_BASE_H
#define PASC_BASE_H

#include "pascal.h"
#include "pascal_base_interface_vector.h"

namespace PASCAL_NS
{

class ParScaleBase
{
  friend class ParScaleBaseAccessible;

  public:

    ParScaleBase(ParScale *ptr) :
      pscl_(*ptr),
      paScalBaseInterfaceVector_(ptr->paScalBaseInterfaceVector_),
      comm_(ptr->comm_),
      input_(ptr->input_),
      output_(ptr->output_),
      control_(ptr->control_),
      coupling_(ptr->coupling_),
      error_(ptr->error_),
      particleMesh_(ptr->particleMesh_),
      particleData_(ptr->particleData_),
      fluidData_(ptr->fluidData_),
      modelContainer_(ptr->modelContainer_),
      modelEqnContainer_(ptr->modelEqnContainer_),
      modelPhaseChangeContainer_(ptr->modelPhaseChangeContainer_),
      modelChemistryContainer_(ptr->modelChemistryContainer_),
      callingProgram_(ptr->callingProgram_),
      chemistryReader_(ptr->chemistryReader_),
      chemistryReaderCHEMKIN_(ptr->chemistryReaderCHEMKIN_),
      couplingModel_(ptr->couplingModel_)
    {}

    virtual ~ParScaleBase() {}

  protected:

    inline ParScale*               pascal_ptr()     const {return &pscl_;}
    inline const ParScaleBaseInterfaceVector& pascalInterface() const {return *paScalBaseInterfaceVector_;}

    inline const Comm&           comm()           const {return *comm_;}
    inline const Input&          input()          const {return *input_;}
    inline const Output&         output()         const {return *output_;}
    inline const Control&        control()        const {return *control_;}
    inline const Coupling&       coupling()       const {return *coupling_;}
    inline const Error&          error()          const {return *error_;}
    inline const ParticleMesh&   particleMesh()   const {return *particleMesh_;}
    inline const ParticleData&   particleData()   const {return *particleData_;}
    inline const FluidData&      fluidData()      const {return *fluidData_;}
    inline const ModelContainer& modelContainer() const {return *modelContainer_;}
    inline const ModelEqnContainer& modelEqnContainer() const {return *modelEqnContainer_;}
    inline const ModelPhaseChangeContainer& modelPhaseChangeContainer() const {return *modelPhaseChangeContainer_;}
    inline const ModelChemistryContainer& modelChemistryContainer() const {return *modelChemistryContainer_;}
    inline const ChemistryReaderCHEMKIN& chemistryReaderCHEMKIN() const {return *chemistryReaderCHEMKIN_;}
    inline const CouplingModel&       couplingModel()       const {return *couplingModel_;}

    inline void* callingProgram() { return callingProgram_;};

  private:

    ParScale &pscl_;
    ParScaleBaseInterfaceVector *&paScalBaseInterfaceVector_; // vehicle for global operations

    Comm *&comm_;                    // inter-processor communication
    Input *&input_;                  // input to simulation - input script processing
    Output *&output_;                // simulation output
    Control *&control_;              // simulation control
    Coupling *&coupling_;            // coupling to other codes
    Error *&error_;                  // error handling
    ParticleMesh *&particleMesh_;    // storage for particle mesh
    ParticleData *&particleData_;    // storage for particle data
    FluidData *&fluidData_;          // storage for fluid data
    ModelContainer *&modelContainer_;// container for physical/chemical models
    ModelEqnContainer *&modelEqnContainer_;// container for (discretized) equations
    ModelPhaseChangeContainer *&modelPhaseChangeContainer_;// container for phase change (e.g., evaporation)
    ModelChemistryContainer   *&modelChemistryContainer_;// container for reactions
    ChemistryReader *&chemistryReader_;
    ChemistryReaderCHEMKIN *&chemistryReaderCHEMKIN_;
    CouplingModel *&couplingModel_;            // coupling to other codes

    void* callingProgram_;           //pointer to a calling program
};

} //end PASCAL_NS

#endif
