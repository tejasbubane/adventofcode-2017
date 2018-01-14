open Jest;

describe(
  "coordinates",
  () => {
    open Expect;
    test("1", () => expect(SpiralMemory.coordinates(1)) |> toEqual((0, 0)));
    test("2", () => expect(SpiralMemory.coordinates(2)) |> toEqual((1, 0)));
    test("3", () => expect(SpiralMemory.coordinates(3)) |> toEqual((1, 1)));
    test("4", () => expect(SpiralMemory.coordinates(4)) |> toEqual((0, 1)));
    test("5", () => expect(SpiralMemory.coordinates(5)) |> toEqual(((-1), 1)));
    test("12", () => expect(SpiralMemory.coordinates(12)) |> toEqual((2, 1)));
    test("23", () => expect(SpiralMemory.coordinates(23)) |> toEqual((0, (-2))))
  }
);

describe(
  "distance",
  () => {
    open Expect;
    test("1", () => expect(SpiralMemory.distance(1)) |> toBe(0));
    test("12", () => expect(SpiralMemory.distance(12)) |> toBe(3));
    test("23", () => expect(SpiralMemory.distance(23)) |> toBe(2));
    test("1024", () => expect(SpiralMemory.distance(1024)) |> toBe(31));
    test("347991", () => expect(SpiralMemory.distance(347991)) |> toBe(480))
  }
);
