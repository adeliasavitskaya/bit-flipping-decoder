## Основные функции

- `BitFlippingDecoder(y, H, I_max)` — декодер bit-flipping (`bfd.h`)
- `calculateFER(H, p, I_max, nFrames, seed)` — генерирует случайные кодовые слова,
  пропускает их через канал, декодирует и считает FER (`FERcalculate.h`)

## Вспомогательные функции

- `findPivots`, `makeG` — построение порождающей матрицы G по H
- `encode` — кодирование c = u·G
- `channel` — двоичный симметричный канал