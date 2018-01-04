open Jest;

let testInput = [|0, 2, 7, 0|];

let myInput = [|10, 3, 15, 10, 5, 15, 5, 15, 9, 2, 5, 8, 5, 2, 3, 6|];

describe(
  "MemoryRealloc",
  () => {
    open Expect;
    test("iterate - test", () => expect(MemoryRealloc.iterate(testInput, 0, 0)) |> toBe(5));
    test("iterate - myInput", () => expect(MemoryRealloc.iterate(myInput, 0, 0)) |> toBe(14029))
  }
);
