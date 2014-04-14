Name:           nemo-gst-interfaces
Summary:        Nemo mobile GStreamer interfaces
Version:        1.0.0
Release:        1
Group:          Applications/Multimedia
License:        LGPL2.1+
URL:            http://jollamobile.com
Source0:        %{name}-%{version}.tar.gz
BuildRequires:  pkgconfig(gstreamer-plugins-base-1.0)

%description
Nemo mobile GStreamer interfaces

%package -n nemo-gstreamer1.0-interfaces
Summary: gstreamer interface used for video rendering
Group: Applications/Multimedia
%description -n nemo-gstreamer1.0-interfaces
%{summary}
%post -n nemo-gstreamer1.0-interfaces -p /sbin/ldconfig
%postun -n nemo-gstreamer1.0-interfaces -p /sbin/ldconfig

%package -n nemo-gstreamer1.0-interfaces-devel
Summary: gstreamer interface used for video rendering devel package
Group: Applications/Multimedia
Requires:  nemo-gstreamer1.0-interfaces = %{version}-%{release}

%description -n nemo-gstreamer1.0-interfaces-devel
%{summary}
%post -n nemo-gstreamer1.0-interfaces-devel -p /sbin/ldconfig
%postun -n nemo-gstreamer1.0-interfaces-devel -p /sbin/ldconfig

%prep
%setup -q

%build
%autogen
%configure
make %{?jobs:-j%jobs}

%install
%make_install

%files -n nemo-gstreamer1.0-interfaces
%defattr(-,root,root,-)
%{_libdir}/libgstnemointerfaces-1.0.so.*
%{_libdir}/libgstnemometa-1.0.so.*

%files -n nemo-gstreamer1.0-interfaces-devel
%defattr(-,root,root,-)
%{_libdir}/libgstnemointerfaces-1.0.so
%{_libdir}/libgstnemometa-1.0.so
%{_libdir}/pkgconfig/*-1.0.pc
%{_includedir}/gstreamer-1.0/gst/interfaces/nemovideotexture.h
%{_includedir}/gstreamer-1.0/gst/meta/nemometa.h
