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
      // In Java we cannot bitshift a byte, so it'll get converted into an int/long
      // Thus we have the 0xFF bitmask to ensure that `read` does not overflow.
      int read = ((cur & 0xFF) >>> remainderSize);
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

    boolean isPadding = false;
    int remainder = 8;
    int curByte = 0;

    // 000000:00|0000:0000|00:000000|000000:00|
    for (char c : data.toCharArray()) {
      if (c == PADDING) {
        // When we encounter padding, then curByte is just zeros that must be ignored!
        // Example: Base64 encoded string: TWE=
        // Example: 010011:010110:000100:------
        // ...........................^^ This is what is in current byte and these zeros are not
        // part of the original data
        isPadding = true;
        break;
      }

      int idx = INDEX_MAP.get(c);

      if (remainder == 8) {
        curByte = idx << 2;
        remainder = 2;
      } else {
        int cutSize = 6 - remainder;
        curByte = curByte | (idx >>> cutSize);
        result.add((byte) (curByte & 0xFF));

        curByte = idx & ((1 << cutSize) - 1);
        curByte = curByte << (8 - cutSize);
        remainder = 8 - cutSize;
      }

      if (remainder == 0) {
        remainder = 8;
        curByte = 0;
      }
    }

    if ((!isPadding) & (remainder > 0 && remainder < 8)) {
      result.add((byte) (curByte & 0xFF));
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
