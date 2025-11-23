#pragma once

template <typename T>
class Predicate {
    bool apply(T) const;
    Predicate<T>* copy() const;
};

template <typename T>
class Predicates {
public:
    // TODO: impl those, and check if those below are correctly declared
    class ConnectivePredicate : public Predicate<T> {};
    class FunctionPredicate : public Predicate<T> {
    public:
        FunctionPredicate(bool (*predicate)(T)) { this->mPredicate = predicate; }

        static FunctionPredicate* createPredicate(bool (*predicate)(T)) {
            return new FunctionPredicate(predicate);
        }

        bool (*mPredicate)(T);
    };
    class ConstantPredicate : public Predicate<T> {
    public:
        ConstantPredicate(bool);
    };
    class EqualToValuePredicate : public Predicate<T> {};
};