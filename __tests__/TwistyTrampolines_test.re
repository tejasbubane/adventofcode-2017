open Jest;

open TwistyTrampolinesTestInputs;

describe(
  "calcSteps",
  () => {
    open Expect;
    test("example", () => expect(TwistyTrampolines.calcSteps(example)) |> toBe(5));
    test("myInput", () => expect(TwistyTrampolines.calcSteps(myInput)) |> toBe(373160))
  }
);
