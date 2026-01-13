# RTOS Microkernel-Style Service Framework

A microkernel-inspired architecture built on top of an RTOS.
Each service runs in its own thread and communicates only via
centralized message routing.

## Features
- Multithreaded services
- Message-based IPC
- Central router
- ISR-safe messaging
- Deterministic scheduling

## Architecture
RTOS Kernel → Microkernel Layer → Services
