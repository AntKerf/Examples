package webscrap;

/**
 *
 * @author AntKerf
 */
public class MyUtil {

    // контейнер пара
    public static class Pair<F, S> {

        private F first;
        private S second;

        //Конструктор с параметрами 
        public Pair(F _first, S _second) {
            this.first = _first;
            this.second = _second;
        }

        //Конструктор копирования
        public Pair(Pair<F, S> toCopy) {
            this.first = toCopy.first;
            this.second = toCopy.second;
        }

        public F getFirst() {
            return this.first;
        }

        public S getSecond() {
            return this.second;
        }

        public void setFirst(F newFirst) {
            this.first = newFirst;
        }

        public void setSecond(S newSecond) {
            this.second= newSecond;
        }

    }
}
