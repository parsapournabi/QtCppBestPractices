#ifndef UTILS_H
#define UTILS_H

#define DEFINE_BACKEND_PROPERTY() \
Q_PROPERTY(ClockCircleBackend *backend READ backend CONSTANT) \
    public: \
    ClockCircleBackend *backend() const;

#define DECLARE_BACKEND_PROPERTY(cls) \
ClockCircleBackend *cls::backend() const { return m_backend.get(); }

#endif // UTILS_H
