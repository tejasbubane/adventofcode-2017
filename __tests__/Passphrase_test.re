open Jest;

open PassphraseTestInputs;

/* Part 1 */
describe(
  "valid1",
  () => {
    open Expect;
    let compare = Passphrase.compare1;
    test(phrase1, () => expect(Passphrase.valid(phrase1, compare)) |> toEqual(true));
    test(phrase2, () => expect(Passphrase.valid(phrase2, compare)) |> toEqual(false));
    test(phrase3, () => expect(Passphrase.valid(phrase3, compare)) |> toEqual(true))
  }
);

describe(
  "countValid1",
  () => {
    open Expect;
    test("all given phrases", () => expect(Passphrase.countValid1(allPhrases1)) |> toBe(2));
    test("my phrase", () => expect(Passphrase.countValid1(myInput)) |> toBe(466))
  }
);

/* Part 2 */
describe(
  "valid2",
  () => {
    open Expect;
    let compare = Passphrase.compare2;
    test(phrase4, () => expect(Passphrase.valid(phrase4, compare)) |> toEqual(true));
    test(phrase5, () => expect(Passphrase.valid(phrase5, compare)) |> toEqual(false));
    test(phrase6, () => expect(Passphrase.valid(phrase6, compare)) |> toEqual(true));
    test(phrase7, () => expect(Passphrase.valid(phrase7, compare)) |> toEqual(true));
    test(phrase8, () => expect(Passphrase.valid(phrase8, compare)) |> toEqual(false))
  }
);

describe(
  "countValid2",
  () => {
    open Expect;
    test("all given phrases", () => expect(Passphrase.countValid2(allPhrases2)) |> toBe(3));
    test("my phrase", () => expect(Passphrase.countValid2(myInput)) |> toBe(251))
  }
);
