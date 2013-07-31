Name:           nemo-gst-interfaces
Summary:        Nemo mobile GStreamer interfaces
Version:        1.0.0
Release:        1
Group:          Applications/Multimedia
License:        LGPL2.1+
URL:            http://jollamobile.com
Source0:        %{name}-%{version}.tar.gz
BuildRequires:  pkgconfig(gstreamer-plugins-base-0.10)

%description
Nemo mobile GStreamer interfaces

%package -n nemo-gstreamer0.10-interfaces
Summary: gstreamer interface used for video rendering
Group: Applications/Multimedia
%description -n nemo-gstreamer0.10-interfaces
%{summary}
%post -n nemo-gstreamer0.10-interfaces -p /sbin/ldconfig
%postun -n nemo-gstreamer0.10-interfaces -p /sbin/ldconfig

%package -n nemo-gstreamer0.10-interfaces-devel
Summary: gstreamer interface used for video rendering devel package
Group: Applications/Multimedia
%description -n nemo-gstreamer0.10-interfaces-devel
%{summary}
%post -n nemo-gstreamer0.10-interfaces-devel -p /sbin/ldconfig
%postun -n nemo-gstreamer0.10-interfaces-devel -p /sbin/ldconfig

%prep
%setup -q

%build
%autogen
%configure
make %{?jobs:-j%jobs}

%install 
%make_install

%files -n nemo-gstreamer0.10-interfaces
%defattr(-,root,root,-)
%{_libdir}/libgstnemointerfaces-0.10.so.*

%files -n nemo-gstreamer0.10-interfaces-devel
%defattr(-,root,root,-)
%{_libdir}/libgstnemointerfaces-0.10.so
%{_libdir}/pkgconfig/nemo-gstreamer-interfaces-0.10.pc
%{_includedir}/gstreamer-0.10/gst/interfaces/nemovideotexture.h
