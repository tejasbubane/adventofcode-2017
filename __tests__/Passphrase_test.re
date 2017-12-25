open Jest;

describe(
  "valid",
  () => {
    open Expect;
    open TestInputs;
    test(input1, () => expect(Passphrase.valid(input1)) |> toEqual(true));
    test(input2, () => expect(Passphrase.valid(input2)) |> toEqual(false));
    test(input3, () => expect(Passphrase.valid(input3)) |> toEqual(true))
  }
);

describe(
  "countValid",
  () => {
    open Expect;
    open TestInputs;
    test("all given inputs", () => expect(Passphrase.countValid(allInputs)) |> toBe(2));
    test("my input", () => expect(Passphrase.countValid(myInput)) |> toBe(466))
  }
);
