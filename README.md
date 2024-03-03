# NanoTekSpice

NanoTekSpice is a logic simulator designed to simulate digital electronic circuits based on a configuration file provided by the user. This readme provides instructions on how to use NanoTekSpice and an overview of its functionality.

## Usage

To use NanoTekSpice, follow these steps:

1. **Create a Configuration File**: Prepare a configuration file (.nts) describing the digital electronic circuit you want to simulate. The configuration file should include:
   - **Chipsets**: Declare and name components that will be used in the circuit.
   - **Links**: Declare links between components, specifying which pins of which components are linked.

2. **Run NanoTekSpice**: Run NanoTekSpice with the following command:
  ```bash
  ./nanotekspice <file.nts>
  ```
Replace `<file.nts>` with the path to your configuration file.

3. **Running**: The NanoTekSpice simulator is equipped with various functionalities, both for running simulations and interacting with the circuit. Below are the commands that the simulator supports when reading from standard input:

- **exit**: Closes the program.
- **display**: Prints the current tick and the values of all inputs and outputs to the standard output. Values are sorted by name in ASCII order.
- **input=value**: Changes the value of an input or clock. Possible values are 0, 1, and U (undefined).
- **simulate**: Simulates a tick of the circuit.
- **loop**: Continuously runs the simulation (simulate, display, simulate, etc.) without displaying a prompt until interrupted by SIGINT (CTRL+C).
- *Additional commands for debug purposes can be added as needed.*

Between commands, the program displays a prompt in the form of `> ` (greater-than sign followed by a space).

When printing a value, if it is undefined, the program displays "U".

Upon reaching the end of its standard input (e.g., CTRL+D), the program stops with status 0.

4. **Configuratiobn file example**

Here's an example of a simple configuration file:

```nts
.chipsets:
input i0
input i1
4081 and0
output out

.links:
i0:1 and0:1
i1:1 and0:2
and0:3 out:1
````

This configuration file describes a circuit with two input components (`i0` and `i1`), a 4081 AND gate (`and0`), and an output component (`out`). The inputs `i0` and `i1` are linked to the first and second inputs of the AND gate `and0`, respectively. The output of the AND gate `and0` is linked to the output component `out`.
