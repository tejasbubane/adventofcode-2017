open Jest;

open TwistyTrampolinesTestInputs;

describe(
  "calcSteps1",
  () => {
    open Expect;
    test("example", () => expect(TwistyTrampolines.calcSteps1(Array.copy(example))) |> toBe(5));
    test(
      "myInput",
      () => expect(TwistyTrampolines.calcSteps1(Array.copy(myInput))) |> toBe(373160)
    )
  }
);

describe(
  "calcSteps2",
  () => {
    open Expect;
    test("example", () => expect(TwistyTrampolines.calcSteps2(Array.copy(example))) |> toBe(10));
    test(
      "myInput",
      () => expect(TwistyTrampolines.calcSteps2(Array.copy(myInput))) |> toBe(26395586)
    )
  }
);
