

#ifndef FLIGHTGEAR_ICOMMAND_H
#define FLIGHTGEAR_ICOMMAND_H
class ICommand {

 public:
  virtual void doCommand() = 0;
  virtual ~ICommand() = default;
};
#endif //FLIGHTGEAR_ICOMMAND_H
