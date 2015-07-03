//------------------------------------------------------------------------------
//  This file is auto-generated. Please do not make any changes.
//------------------------------------------------------------------------------
#ifndef LTMERGE_H
#define LTMERGE_H

#include <QSet>
#include <QList>
#include <QPair>
#include <QStringList>

typedef QList<int> Indices;
typedef QPair<int, int> Interval;
typedef QList<Interval> IntervalList;

class Intervals
{
public:
    static bool lessThan(const Interval& i0, const Interval& i1)
    {
        return i0.first < i1.first;
    }

    static IntervalList intervals(const Indices& indices)
    {
        Indices indicesSorted(indices);
        qSort(indicesSorted);

        IntervalList result;
        const int indecesCount = indicesSorted.count();
        if (indecesCount > 0)
        {
            int indexLast = indecesCount - 1;
            for (int i = indecesCount-1; i > 0; --i)
            {
                if (indicesSorted.at(i) - indicesSorted.at(i-1) > 1)
                {
                    result.append(Interval(indicesSorted.at(i), indicesSorted.at(indexLast)));
                    indexLast = i-1;
                }
            }
            result.append(Interval(indicesSorted.at(0), indicesSorted.at(indexLast)));
        }
        qSort(result.begin(), result.end(), &lessThan);
        return result;
    }
};

template <typename T> class HashedList
{
public:
    typedef QStringList (*FuncPtrHash)(const T&);

private:
    const FuncPtrHash mHash;
    QHash<QString, int> mIndicesByKeys;
    QMultiHash<int, QString> mKeysByIndices;
    QList<T> mData;

public:
    void generateIndices(const QList<T>& data, QHash<QString, int>& indicesByKeys, QMultiHash<int, QString>& keysByIndices)
    {
        indicesByKeys.clear();
        keysByIndices.clear();
        const int count = data.count();
        for (int i = 0; i < count; ++i)
        {
            const T& item = data.at(i);
            const QStringList keys = this->mHash(item);
            foreach (const QString& key, keys) {
                if (!indicesByKeys.contains(key)) {
                    indicesByKeys.insert(key, i);
                    keysByIndices.insertMulti(i, key);
                }
            }
        }
    }

    explicit HashedList(const FuncPtrHash hash) :
        mHash(hash),
        mIndicesByKeys(),
        mKeysByIndices(),
        mData()
    {
        Q_ASSERT(this->mHash);
    }
    const QHash<QString, int>& indices() const { return this->mIndicesByKeys; }
    const QMultiHash<int, QString>& keys() const { return this->mKeysByIndices; }
    const QList<T>& data() const { return this->mData; }
    int count() const { return this->mData.count(); }
    const T &at(int i) const { return this->mData.at(i); }
    int indexOf(const T &t, QString* matchkey = 0) const
    {
        const QStringList keys = this->mHash(t);
        Q_ASSERT(!keys.isEmpty());

        foreach (const QString& key, keys) {
            const int index = this->mIndicesByKeys.value(key, -1);
            if (index >= 0) {
                if (matchkey) {
                    *matchkey = key;
                }
                return index;
            }
        }
        if (matchkey) {
            *matchkey = QString::null;
        }
        return -1;
    }
    void append(const T &t)
    {
        const bool notExists = this->indexOf(t) == -1;
        Q_ASSERT(notExists);

        if (notExists)
        {
            const int index = this->mData.count();

            const QStringList keys = this->mHash(t);
            Q_ASSERT(!keys.isEmpty());

            this->mData.append(t);

            foreach (const QString& key, keys) {
                this->mIndicesByKeys.insert(key, index);
                this->mKeysByIndices.insertMulti(index, key);
            }
        }
        //validate();
    }

    void removeAt(int i)
    {
        this->takeAt(i);
    }

    T takeAt(int i)
    {
        const int count = this->mData.count();
        const bool indexIsValid = i >= 0 && i < count;
        Q_ASSERT(indexIsValid);

        if (indexIsValid)
        {
            const QStringList keys = this->mHash(this->mData.at(i));

            foreach (const QString& key, keys)
                this->mIndicesByKeys.remove(key);
            this->mKeysByIndices.remove(i);

            const T result = this->mData.takeAt(i);

            for (int j = i + 1; j < count; ++j)
            {
                const QList<QString> movedKeys = this->mKeysByIndices.values(j);
                this->mKeysByIndices.remove(j);
                foreach (const QString& movedKey, movedKeys) {
                    this->mKeysByIndices.insertMulti(j - 1, movedKey);
                    if (this->mIndicesByKeys.value(movedKey) > i)
                        --this->mIndicesByKeys[movedKey];
                }
            }

            return result;
        }
        //validate();

        return T();
    }
    void replace(int i, const T &t)
    {
        const int count = this->mData.count();
        const bool indexIsValid = i >= 0 && i < count;
        Q_ASSERT(indexIsValid);

        if (indexIsValid)
        {
            const QStringList keysPrev = this->mHash(this->mData.at(i));
            Q_ASSERT(!keysPrev.isEmpty());

            const QStringList keysCurr = this->mHash(t);
            Q_ASSERT(!keysCurr.isEmpty());

            foreach (const QString& key, keysPrev)
                this->mIndicesByKeys.remove(key);
            this->mKeysByIndices.remove(i);

            this->mData.replace(i, t);

            foreach (const QString& key, keysCurr) {
                this->mIndicesByKeys.insert(key, i);
                this->mKeysByIndices.insertMulti(i, key);
            }
        }
        //validate();
    }

private:
    void validate()
    {
        {
            const QList<int> uniqueIndices = this->mIndicesByKeys.values().toSet().toList();
            Q_ASSERT(this->mData.count() == uniqueIndices.count());
        }
        {
            const QList<int> uniqueIndices = this->mKeysByIndices.keys();
            Q_ASSERT(this->mData.count() == uniqueIndices.count());
        }
        {
            const QList<QString> keys = this->mIndicesByKeys.keys();
            foreach (const QString& key, keys) {
                const int index = this->mIndicesByKeys.value(key);
                Q_ASSERT(index != -1);
                const QStringList keysTarget = this->mHash(this->mData.at(index));
                Q_ASSERT(keysTarget.contains(key));
            }
        }
        {
            const QList<int> indices = this->mKeysByIndices.keys();
            foreach (int index, indices) {
                const QStringList keys = this->mKeysByIndices.values(index);
                const QStringList keysTarget = this->mHash(this->mData.at(index));
                Q_ASSERT(!(keys.toSet() & keysTarget.toSet()).isEmpty());
            }
        }
        {
            const int count = this->mData.count();
            for (int index = 0; index < count; ++index)
            {
                const T& value = this->mData.at(index);
                const QStringList keys = this->mHash(value);
                foreach (const QString& key, keys) {
                    const int idx = this->mIndicesByKeys.value(key);
                    Q_ASSERT(index == idx);
                }
            }
        }
    }
};

#endif // LTMERGE_H
