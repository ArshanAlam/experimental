package base64;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Base64 {
  private static final char[] CHAR_MAP = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
      'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd',
      'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
      'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};

  private static final char PADDING = '=';
  private static final Map<Character, Integer> INDEX_MAP = new HashMap<>();

  static {
    for (int i = 0; i < CHAR_MAP.length; i++) {
      INDEX_MAP.put(CHAR_MAP[i], i);
    }
  }

  public static String encode(byte[] data) {
    StringBuilder result = new StringBuilder();

    int remainder = 0;
    int readSize = 6;
    // [00000000][00000000]

    for (byte cur : data) {
      int remainderSize = 8 - readSize;
      int read = cur >> remainderSize;
      int idx = remainder | read;

      result.append(CHAR_MAP[idx]);

      remainder = cur & ((1 << remainderSize) - 1);

      int nextReadSize = 6 - remainderSize;

      // The remainder has a valid index that doesn't need the next read
      // thus add it to the result.
      if (nextReadSize == 0) {
        nextReadSize = 6;
        result.append(CHAR_MAP[remainder]);
        remainder = 0;
      }

      remainder = remainder << nextReadSize;
      readSize = nextReadSize;
    }

    if (readSize > 0 && readSize < 6) {
      result.append(CHAR_MAP[remainder]);

      // Add the padding
      if (3 - (data.length % 3) == 2) {
        result.append(PADDING);
        result.append(PADDING);
      } else {
        result.append(PADDING);
      }
    }

    return result.toString();
  }

  public static byte[] decode(String data) {
    List<Byte> result = new ArrayList<>();

    int remainderSize = 8;
    int curByte = 0;

    for (char c : data.toCharArray()) {
      if (c == PADDING) {
        break;
      }

      int idx = INDEX_MAP.get(c);

      if (remainderSize == 8) {
        curByte = idx;
        remainderSize -= 6;
        continue;
      }

      curByte = curByte << remainderSize;
      curByte = curByte | (idx >>> (6 - remainderSize));

      result.add((byte) (curByte & 0xFF));

      int nextReadSize = 6 - remainderSize;
      curByte = idx & ((1 << nextReadSize) - 1);
      remainderSize = 8 - nextReadSize;

    }

    System.err.println("Remainder Size Decode " + remainderSize + " " + curByte);
    if (remainderSize > 0 && remainderSize < 8) {
      result.add((byte) ((curByte << remainderSize) & 0xFF));
    }

    byte[] resultArray = new byte[result.size()];
    for (int i = 0; i < resultArray.length; i++) {
      resultArray[i] = result.get(i);
    }

    return resultArray;
  }

  public static void main(String[] args) throws IOException {
    String encoded = encode(System.in.readAllBytes());
    byte[] decoded = decode(encoded);
    System.out.writeBytes(decoded);
  }
}
